class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.size() + 1);
        
        for (int i = 1; i <= word1.size(); i++) {
            vector<int> newDp(word2.size() + 1);
            
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    newDp[j] = 1 + dp[j - 1];
                } else {
                    newDp[j] = max(dp[j], newDp[j - 1]);
                }
            }
            
            dp = newDp;
        }
        
        return word1.size() + word2.size() - 2 * dp.back();
    }
    
    int minDistance1(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        
        for (int i = 0; i <= word1.size(); i++) {
            for (int j = 0; j <= word2.size(); j++) {
                if (not i or not j) {
                    dp[i][j] = 0;
                } else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return word1.size() + word2.size() - 2 * dp.back().back();
    }
};