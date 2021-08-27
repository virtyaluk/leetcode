class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> horSkyline(m), vertSkyline(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                horSkyline[j] = max(horSkyline[j], grid[i][j]);
                vertSkyline[i] = max(vertSkyline[i], grid[i][j]);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += min(horSkyline[j], vertSkyline[i]) - grid[i][j];
            }
        }
        
        return ans;
    }
};