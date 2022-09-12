class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ans = 0, maxLen = 0;
        
        for (vector<int>& rect: rectangles) {
            int k = min(rect[0], rect[1]);
            
            if (k == maxLen) {
                ans++;
            } else if (k > maxLen) {
                maxLen = k;
                ans = 1;
            }
        }
        
        return ans;
    }
};