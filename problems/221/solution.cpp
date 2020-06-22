class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (not i or not j) {
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],
                        dp[i - 1][j],
                        dp[i - 1][j - 1]
                    });
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans * ans;
    }
};