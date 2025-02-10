class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        vector<int> rows(size(grid)),
            cols(size(grid.front()));

        for (int i = 0; i < size(grid); i++) {
            for (int j = 0; j < size(grid[i]); j++) {
                if (grid[i][j]) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        
        for (int i = 0; i < size(grid); i++) {
            for (int j = 0; j < size(grid[i]); j++) {
                ans += grid[i][j] and (cols[j] > 1 or rows[i] > 1);
            }
        }
        
        return ans;
    }
};