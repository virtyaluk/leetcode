class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = size(grid),
            n = size(grid.front());
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i + 1 < m and grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
                
                if (j + 1 < n and grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};