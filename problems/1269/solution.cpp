const int MOD = 1e9 + 7;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(steps + 1, -1));
        
        return dfs(dp, steps, arrLen, 0);
    }
    
    int dfs(vector<vector<int>>& dp, int steps, int n, int idx) {
        if (not steps) {
            return not idx;
        }
        
        if (dp[steps][idx] != -1) {
            return dp[steps][idx];
        }
        
        int ans = dfs(dp, steps - 1, n, idx) % MOD;
        
        if (idx - 1 >= 0) {
            ans = (ans + dfs(dp, steps - 1, n, idx - 1)) % MOD;
        }
        
        if (idx + 1 < n) {
            ans = (ans + dfs(dp, steps - 1, n, idx + 1)) % MOD;
        }
        
        return dp[steps][idx] = ans;
    }
};