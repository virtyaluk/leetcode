class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = size(s);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                // if (not i or not j) {
                //     dp[i][j] = i or j;
                if (not i) {
                    dp[i][j] = j;
                } else if (not j) {
                    dp[i][j] = i;
                } else if (s[i - 1] == s[n - j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1]});
                }
            }
        }
        
        return dp[n][n] <= k * 2;
    }
};