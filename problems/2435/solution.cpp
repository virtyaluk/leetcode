const int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = size(grid),
            n = size(grid.front());
        vector<vector<vector<long long>>> dp(m + 1, vector<vector<long long>>(n + 1, vector<long long>(k)));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 and j == 1) {
                    dp[i][j][grid[0][0] % k] = 1;
                    
                    continue;
                }

                int val = grid[i - 1][j - 1] % k;

                for (int r = 0; r < k; r++) {
                    int prevMod = (r - val + k) % k;
                    dp[i][j][r] = (dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod]) % MOD;
                }
            }
        }

        return dp.back().back().front();
    }
};