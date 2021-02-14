const int MOD = 1e9 + 7;

class Solution {
public:
    int findDerangement(int n) {
        vector<long long int> dp(max(n + 1, 2));
        dp[0] = 1;
        dp[1] = 0;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = ((dp[i - 1] + dp[i - 2]) * (i - 1l)) % MOD;
        }
        
        return dp[n];
    }
};