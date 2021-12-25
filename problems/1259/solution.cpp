const int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfWays(int n) {
        n /= 2;
        vector<long long int> dp(n + 1);
        
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
                dp[i] = dp[i] % MOD;
            }
        }

        return dp[n];
    }
};