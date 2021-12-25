const int MOD = 1e9 + 7;

class Solution {
public:
    int countVowelPermutation(int n) {
        int ans = 0,
            a = 0, e = 1, i = 2, o = 3, u = 4;
        vector<long long int> dp(5, 1);
        
        for (int j = 1; j < n; j++) {
            vector<long long int> newDp(5);
            
            newDp[a] = (dp[e] + dp[i] + dp[u]) % MOD;
            newDp[e] = (dp[a] + dp[i]) % MOD;
            newDp[i] = (dp[e] + dp[o]) % MOD;
            newDp[o] = dp[i] % MOD;
            newDp[u] = (dp[i] + dp[o]) % MOD;
            
            dp = newDp;
        }
        
        for (const int& dpi: dp) {
            ans = (ans + dpi) % MOD;
        }
        
        return ans;
    }
};