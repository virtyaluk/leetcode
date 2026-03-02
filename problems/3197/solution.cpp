class Solution {
private:
    int minSum(vector<vector<int>>& g, int u, int d, int l, int r) {
        int mini = size(g),
            maxi = 0,
            minj = size(g.front()),
            maxj = 0;
        
        for (int i = u; i <= d; i++) {
            for (int j = l; j <= r; j++) {
                if (g[i][j] == 1) {
                    mini = min(mini, i);
                    minj = min(minj, j);
                    maxi = max(maxi, i);
                    maxj = max(maxj, j);
                }
            }
        }

        return mini <= maxi ? (maxi - mini + 1) * (maxj - minj + 1) : INT_MAX / 3;
    }

    vector<vector<int>> rotate(vector<vector<int>>& vvi) {
        int n = size(vvi),
            m = size(vvi.front());
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[m - j - 1][i] = vvi[i][j];
            }
        }

        return ans;
    }

    int solve(vector<vector<int>>& g) {
        int n = size(g),
            m = size(g.front()),
            ans = n * m;
        
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                ans = min(ans, minSum(g, 0, i, 0, m - 1) + minSum(g, i + 1, n - 1, 0, j) + minSum(g, i + 1, n - 1, j + 1, m - 1));
                ans = min(ans, minSum(g, 0, i, 0, j) + minSum(g, 0, i, j + 1, m - 1) + minSum(g, i + 1, n - 1, 0, m - 1));
            }
        }

        for (int i = 0; i + 2 < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                ans = min(ans, minSum(g, 0, i, 0, m - 1) + minSum(g, i + 1, j, 0, m - 1) + minSum(g, j + 1, n - 1, 0, m - 1));
            }
        }
        
        return ans;
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        vector<vector<int>> rg = rotate(grid);

        return min(solve(grid), solve(rg));
    }
};