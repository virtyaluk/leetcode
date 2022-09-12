const int MOD = 1e9 + 7;

class Solution {
public:
    int waysToDistribute(int n, int k) {
        vector<int> dp(1001 * 1001);
        
        return dfs(dp, n, k);
    }
    
    int dfs(vector<int>& dp, int n, int k) {
        if (not n or not k or n < k) {
            return 0;
        }
        
        if (k == 1 or n == k) {
            return 1;
        }
        
        if (dp[n * 1001 + k]) {
            return dp[n * 1001 + k];
        }
        
        int ans = (1l * k * dfs(dp, n - 1, k) + dfs(dp, n - 1, k - 1)) % MOD;
        
        return dp[n * 1001 + k] = ans;
    }
};