class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        
        sort(points.begin(), points.end(), [](vector<int> &l, vector<int> &r) {
            return l[1] < r[1];
        });
        int ans = 1, start, end, lastEnd = points.front().back();
        
        for (vector<int> point: points) {
            start = point.front();
            end = point.back();
            
            if (start > lastEnd) {
                ans++;
                lastEnd = end;
            }
        }
        
        return ans;
    }
};