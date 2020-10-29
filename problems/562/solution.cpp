class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int ans = 0, m = size(mat), n = size(mat.back());
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4)));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    dp[i][j][0] = j > 0 ? 1 + dp[i][j - 1][0] : 1;
                    dp[i][j][1] = i > 0 and j > 0 ? 1 + dp[i - 1][j - 1][1] : 1;
                    dp[i][j][2] = i > 0 ? 1 + dp[i - 1][j][2] : 1;
                    dp[i][j][3] = i > 0 and j + 1 < n ? 1 + dp[i - 1][j + 1][3] : 1;
                    
                    ans = max(ans, *max_element(begin(dp[i][j]), end(dp[i][j])));
                }
            }
        }
        
        return ans;
    }
};