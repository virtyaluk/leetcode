class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = size(word1), n = size(word2);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (not i) {
                    dp[i][j] = j;
                } else if (not j) {
                    dp[i][j] = i;
                } else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                }
            }
        }
        
        return dp.back().back();
    }
};