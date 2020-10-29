class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (const string& str: strs) {
            int zeros = count(begin(str), end(str), '0');
            int ones = str.size() - zeros;
            
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }
        
        return dp[m][n];
        
    }
    
    int findMaxForm1(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size())));

        return helper(strs, m, n, 0, memo);
    }
    
    int helper(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>>& memo) {
        if (i == strs.size() or m + n == 0) {
            return 0;
        }
        
        if (memo[m][n][i] != 0) {
            return memo[m][n][i];
        }
        
        int zeros = count(begin(strs[i]), end(strs[i]), '0');
        int ones = strs[i].size() - zeros;
        
        int take = 0, skip = helper(strs, m, n, i + 1, memo);
        
        if (m >= zeros and n >= ones) {
            take = 1 + helper(strs, m - zeros, n - ones, i + 1, memo);
        }
        
        return memo[m][n][i] = max(take, skip);
    }
};