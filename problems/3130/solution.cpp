const int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2)));

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                for (int lastBit = 0; lastBit <= 1; lastBit++) {
                    if (i == 0) {
                        dp[i][j][lastBit] = lastBit == 0 or j > limit ? 0 : 1;
                    } else if (j == 0) {
                        dp[i][j][lastBit] = lastBit == 1 or i > limit ? 0 : 1;
                    } else if (lastBit == 0) {
                        dp[i][j][lastBit] = dp[i - 1][j].front() + dp[i - 1][j][1];

                        if (i > limit) {
                            dp[i][j][lastBit] -= dp[i - limit - 1][j][1];
                        }
                    } else {
                        dp[i][j][lastBit] = dp[i][j - 1].front() + dp[i][j - 1][1];

                        if (j > limit) {
                            dp[i][j][lastBit] -= dp[i][j - limit - 1].front();
                        }
                    }

                    dp[i][j][lastBit] %= MOD;

                    if (dp[i][j][lastBit] < 0) {
                        dp[i][j][lastBit] += MOD;
                    }
                }
            }
        }

        return (dp[zero][one].front() + dp[zero][one][1]) % MOD;
    }
};