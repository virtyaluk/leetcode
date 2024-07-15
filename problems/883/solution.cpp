class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        
        for (int i = 0; i < size(grid); i++) {
            int row = 0,
                col = 0;
            
            for (int j = 0; j < size(grid); j++) {
                ans += grid[i][j] > 0;
                row = max(row, grid[i][j]);
                col = max(col, grid[j][i]);
            }
            
            ans += row + col;
        }
        
        return ans;
    }
};