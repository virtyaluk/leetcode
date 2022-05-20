class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        
        return pick(dp, grid, 0, 0, n - 1);
    }
    
    int pick(vector<vector<vector<int>>>& dp, vector<vector<int>>& grid, int row, int col1, int col2) {
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size()) {
            return 0;
        }
        
        if (dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }
        
        int ans = grid[row][col1];
        
        if (col1 != col2) {
            ans += grid[row][col2];
        }
        
        if (row != grid.size() - 1) {
            int curMax = 0;
            
            for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++) {
                for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++) {
                   curMax = max(curMax, pick(dp, grid, row + 1, newCol1, newCol2)); 
                }
            }
            
            ans += curMax;
        }
        
        dp[row][col1][col2] = ans;
        
        return ans;
    }
};