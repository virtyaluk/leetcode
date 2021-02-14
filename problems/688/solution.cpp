class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1)));
        
        return dfs(dp, n, k, r, c);
    }
    
    double dfs(
        vector<vector<vector<double>>>& dp,
        int n,
        int k,
        int r,
        int c
    ) { 
        if (r < 0 or r >= n or c < 0 or c >= n) {
            return 0;
        }
        
        if (k == 0) {
            return 1;
        }
        
        if (dp[r][c][k] != 0) {
            return dp[r][c][k];
        }
        
        double ans = dfs(dp, n, k - 1, r - 1, c - 2) +
            dfs(dp, n, k - 1, r - 2, c - 1) +
            dfs(dp, n, k - 1, r - 1, c + 2) +
            dfs(dp, n, k - 1, r - 2, c + 1) +
            dfs(dp, n, k - 1, r + 1, c + 2) +
            dfs(dp, n, k - 1, r + 2, c + 1) +
            dfs(dp, n, k - 1, r + 1, c - 2) +
            dfs(dp, n, k - 1, r + 2, c - 1);
        
        return dp[r][c][k] = ans / 8;
    }
};