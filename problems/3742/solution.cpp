class Solution {
public:
    int maxPathScore(vector<vector<int>>& g, int k) {
        int m = size(g),
            n = size(g.front()),
            ans = INT_MIN;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));
        dp.front().front().front() = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == INT_MIN) {
                        continue;
                    }

                    if (i + 1 < m) {
                        int val = g[i + 1][j],
                            cost = val == 0 ? 0 : 1;
                        
                        if (c + cost <= k) {
                            dp[i + 1][j][c + cost] = max(dp[i + 1][j][c + cost], dp[i][j][c] + val);
                        }
                    }

                    if (j + 1 < n) {
                        int val = g[i][j + 1],
                            cost = val == 0 ? 0 : 1;
                        
                        if (c + cost <= k) {
                            dp[i][j + 1][c + cost] = max(dp[i][j + 1][c + cost], dp[i][j][c] + val);
                        }
                    }
                }
            }
        }

        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }

        return ans < 0 ? -1 : ans;
    }
};