const int MOD = 1e9 + 7;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<long long int>> dp(n + 1, vector<long long int>(k + 1, -1));
        
        return dfs(dp, n, k);
    }
    
    long long int dfs(vector<vector<long long int>>& dp, int n, int k) {
        if (n == k) {
            return 1;
        }
        
        if (n < k or k < 0) {
            return 0;
        }
        
        if (dp[n][k] != -1) {
            return dp[n][k];
        }
        
        long long int ans = dfs(dp, n - 1, k - 1) % MOD;
        ans = (ans + (n - 1) * dfs(dp, n - 1, k) % MOD) % MOD;
        
        return dp[n][k] = ans;
    }
};