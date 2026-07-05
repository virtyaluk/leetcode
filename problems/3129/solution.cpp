const int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2)));

        for (int i = 0; i <= min(zero, limit); i++) {
            dp[i].front().front() = 1;
        }

        for (int i = 0; i <= min(one, limit); i++) {
            dp.front()[i][1] = 1;
        }

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                dp[i][j].front() = i > limit ? dp[i - 1][j].front() + dp[i - 1][j][1] - dp[i - limit - 1][j][1] : dp[i - 1][j].front() + dp[i - 1][j][1];

                dp[i][j].front() = (dp[i][j].front() % MOD + MOD) % MOD;

                dp[i][j][1] = j > limit ? dp[i][j - 1][1] + dp[i][j - 1].front() - dp[i][j - limit - 1].front() : dp[i][j - 1][1] + dp[i][j - 1].front();

                dp[i][j][1] = (dp[i][j][1] % MOD + MOD) % MOD;
            }
        }

        return (dp[zero][one].front() + dp[zero][one][1]) % MOD;
    }
};