class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, helper(matrix, i, j, dp));
            }
        }
        
        return ans;
    }
    
    int helper(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp) {
        if (not dp[i][j]) {
            int m = mat.size(), n = mat[0].size(), cur = mat[i][j];
            
            dp[i][j] = 1 + max({
                j > 0 and mat[i][j - 1] < cur ? helper(mat, i, j - 1, dp) : 0,
                i > 0 and mat[i - 1][j] < cur ? helper(mat, i - 1, j, dp) : 0,
                j < n - 1 and mat[i][j + 1] < cur ? helper(mat, i, j + 1, dp) : 0,
                i < m - 1 and mat[i + 1][j] < cur ? helper(mat, i + 1, j, dp) : 0
            });
        }
        
        return dp[i][j];
    }
    
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int longestIncreasingPath1(vector<vector<int>>& matrix) {
        int ans = 0, m = matrix.size(), n = matrix.back().size();
        vector<vector<int>> memo(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, memo, i, j));
            }
        }
        
        return ans;
    }
    
    int dfs(const vector<vector<int>>& m, vector<vector<int>>& memo, const int i, const int j) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        
        int mm = m.size(), n = m.back().size();
        
        for (const auto& dir: dirs) {
            int x = i + dir[0], y = j + dir[1];
            
            if (x >= 0 and x < mm and y >= 0 and y < n and m[x][y] > m[i][j]) {
                memo[i][j] = max(memo[i][j], dfs(m, memo, x, y));
            }
        }
        
        memo[i][j]++;
        
        return memo[i][j];
    }
};