class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        return 1 + helper(n, 1, 1, dp);
    }
    
    int helper(int n, int cur, int copied, vector<vector<int>>& dp) {
        if (cur > n) {
            return 1000000;
        }
        
        if (not (n - cur)) {
            return 0;
        }
        
        if (dp[cur][copied]) {
            return dp[cur][copied];
        }
        
        int paste = 1 + helper(n, cur + copied, copied, dp);
        int copy = 2 + helper(n, cur + cur, cur, dp);
        
        return dp[cur][copied] = min(paste, copy);
    }
};