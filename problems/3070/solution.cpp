class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = size(grid),
            m = size(grid.front()),
            ans = 0;
        vector<int> cols(m);

        for (int i = 0; i < n; i++) {
            int rows = 0;

            for (int j = 0; j < m; j++) {
                cols[j] += grid[i][j];
                rows += cols[j];

                if (rows <= k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};