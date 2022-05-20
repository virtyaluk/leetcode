class Solution {
public:
    int minInsertions(string s1) {
        int n = size(s1);
        string s2 = s1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        reverse(begin(s2), end(s2));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = 0;
                } else if (j == 0) {
                    dp[i][j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return n - dp.back().back();
    }
};