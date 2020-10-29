class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = size(s);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (not i) {
                    dp[i][j] = j;
                } else if (not j) {
                    dp[i][j] = i;
                } else if (s[i - 1] == s[n - j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return n - dp.back().back() / 2;
    }
};