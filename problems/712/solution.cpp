class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = size(s1), n = size(s2), ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (const char& ch: s1) {
            ans += ch;
        }
        
        for (const char& ch: s2) {
            ans += ch;
        }
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (not i or not j) {
                    dp[i][j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return ans - 2 * dp[m][n];
    }
};