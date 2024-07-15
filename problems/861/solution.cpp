class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int ans = 0,
            rows = size(grid),
            cols = size(grid.front());
        
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < cols; j++) {
                    grid[i][j] = !grid[i][j];// == 0 ? 1 : 0;
                }
            }
        }
        
        for (int j = 0; j < cols; j++) {
            int ones = 0,
                zeros = 0;
            
            for (int i = 0; i < rows; i++) {
                ones += grid[i][j] == 1;
                zeros += grid[i][j] == 0;
            }
            
            if (zeros > ones) {
                for (int i = 0; i < rows; i++) {
                    grid[i][j] = !grid[i][j];// == 0 ? 1: 0;
                }
            }
        }
        
        for (int i = 0; i < rows; i++) {
            int cur = 1;
            
            for (int j = cols - 1; j >= 0; j--) {
                ans += grid[i][j] * cur;
                cur *= 2;
            }
        }
        
        return ans;
    }
};