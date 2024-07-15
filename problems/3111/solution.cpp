class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(begin(points), end(points));
        
        int ans = 1, end = points[0][0] + w;
        
        for (const vector<int>& point: points) {
            if (point[0] > end) {
                ans++;
                end = point[0] + w;
            }
        }
        
        return ans;
    }
};