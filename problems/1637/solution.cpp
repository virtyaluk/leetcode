class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans = 0;
        
        sort(points.begin(), points.end(), [](vector<int> const& l, vector<int> const& r) {
           return l[0] < r[0]; 
        });
        
        for (int i = 1; i < points.size(); i++) {
            ans = max(ans, abs(points[i][0] - points[i - 1][0]));
        }
        
        return ans;
    }
};