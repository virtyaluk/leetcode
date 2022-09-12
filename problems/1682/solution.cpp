class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = size(s);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(27, -1)));
        
        return dfs(s, dp, 0, size(s) - 1, 26);
    }
    
    int dfs(string& s, vector<vector<vector<int>>>& dp, int i, int j, int prev) {
        if (i >= j) {
            return 0;
        }
        
        if (dp[i][j][prev] != -1) {
            return dp[i][j][prev];
        }
        
        if (s[i] - 'a' == prev) {
            return dp[i][j][prev] = dfs(s, dp, i + 1, j, prev);
        }
        
        if (s[j] - 'a' == prev) {
            return dp[i][j][prev] = dfs(s, dp, i, j - 1, prev);
        }
        
        if (s[i] == s[j]) {
            return dp[i][j][prev] = dfs(s, dp, i + 1, j - 1, s[i] - 'a') + 2;
        }
        
        return dp[i][j][prev] = max(
            dfs(s, dp, i + 1, j, prev),
            dfs(s, dp, i, j - 1, prev)
        );
    }
};