class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans = 0,
            m = size(grid),
            n = size(grid.front());
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[j][i] <= grid[j - 1][i]) {
                    ans += grid[j - 1][i] + 1 - grid[j][i];
                    grid[j][i] = grid[j - 1][i] + 1;
                }
            }
        }

        return ans;
    }
};