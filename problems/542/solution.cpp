class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.back().size();
        vector<vector<int>> dp(m, vector<int>(n, pow(10, 5)));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) {
                        dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
                    }
                    
                    if (j > 0) {
                        dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
                    }
                }
            }
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);
                }
                
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j + 1]);
                }
            }
        }
        
        return dp;
    }
};