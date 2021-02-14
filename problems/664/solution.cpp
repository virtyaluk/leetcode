class Solution {
public:
    int strangePrinter(string s) {
        int n = size(s);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return dfs(dp, s, 0, n - 1);
    }
    
    int dfs(vector<vector<int>>& dp, string& s, int i, int j) {
        if (i > j) {
            return 0;
        }
        
        if (dp[i][j] == -1) {
            int k = i;
            
            while (k + 1 <= j and s[k + 1] == s[i]) {
                k++;
            }
            
            dp[i][j] = 1 + dfs(dp, s, k + 1, j);
            
            for (int l = k + 1; l <= j; l++) {
                if (s[l] == s[k]) {
                    dp[i][j] = min(dp[i][j], dfs(dp, s, k + 1, l - 1) + dfs(dp, s, l, j));
                }
            }
        }
        
        return dp[i][j];
    }
};