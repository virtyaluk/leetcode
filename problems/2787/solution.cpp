const int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<long long> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            long long val = pow(i, x);

            if (val > n) {
                break;
            }

            for (int j = n; j >= val; j--) {
                dp[j] = (dp[j] + dp[j - val]) % MOD;
            }
        }

        return dp[n];
    }
};