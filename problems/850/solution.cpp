const int MOD = 1e9 + 7;
typedef long long int i64;

class Solution {
private:
    int x1 = 0, y1 = 1, x2 = 2, y2 = 3;

public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        i64 ans = 0;
        vector<vector<int>> rects;
        
        for (const vector<int>& rect: rectangles) {
            addRect(rects, rect, 0);
        }
        
        for (const vector<int>& rect: rects) {
            ans = (ans + getRectArea(rect)) % MOD;
        }
        
        return ans % MOD;
    }
    
    i64 getRectArea(const vector<int>& rect) {
        return (i64) (rect[x2] - rect[x1]) * (i64) (rect[y2] - rect[y1]);
    }
    
    void addRect(vector<vector<int>>& rects, const vector<int>& rect, int start) {
        if (start >= size(rects)) {
            rects.push_back(rect);
            return;
        }
        
        vector<int> prevRect = rects[start];
        
        // not overlaping
        if (rect[x1] >= prevRect[x2] or rect[y1] >= prevRect[y2] or rect[x2] <= prevRect[x1] or rect[y2] <= prevRect[y1]) {
            addRect(rects, rect, start + 1);
            return;
        }
        
        if (rect[x1] < prevRect[x1]) {
            addRect(rects, {rect[x1], rect[y1], prevRect[x1], rect[y2]}, start + 1);
        }
        
        if (rect[x2] > prevRect[x2]) {
            addRect(rects, {prevRect[x2], rect[y1], rect[x2], rect[y2]}, start + 1);
        }
        
        if (rect[y1] < prevRect[y1]) {
            addRect(rects, {max(rect[x1], prevRect[x1]), rect[y1], min(rect[x2], prevRect[x2]), prevRect[y1]}, start + 1);
        }
        
        if (rect[y2] > prevRect[y2]) {
            addRect(rects, {max(rect[x1], prevRect[x1]), prevRect[y2], min(rect[x2], prevRect[x2]), rect[y2]}, start + 1);
        }
    }
};