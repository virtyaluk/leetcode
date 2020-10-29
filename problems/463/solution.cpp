class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0, m = size(grid), n = size(grid.back());
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (not grid[i][j]) {
                    continue;
                }
                
                ans += not i or not grid[i - 1][j];
                ans += not j or not grid[i][j - 1];
                ans += i == m - 1 or not grid[i + 1][j];
                ans += j == n - 1 or not grid[i][j + 1];
            }
        }
        
        return ans;
    }
};