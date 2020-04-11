typedef unsigned long long int lli;

class Solution {
public:
    int numDistinct(string s, string t) {
//         vector<vector<int>> memo(size(s) + 1, vector<int>(size(t) + 1, -1));
        
//         return dfs(s, t, 0, 0, memo);
        int m = size(s), n = size(t);
        vector<vector<lli>> dp(m + 1, vector<lli>(n + 1, 0));
        
        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j];
                
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }
        
        return dp.front().front();
    }
    
    int dfs(string& s, string& t, int i, int j, vector<vector<int>>& memo) {
        int m = size(s), n = size(t);
        
        if (i == m or j == n or m - i < n - j) {
            return j == n;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int ans = dfs(s, t, i + 1, j, memo);
        
        if (s[i] == t[j]) {
            ans += dfs(s, t, i + 1, j + 1, memo);
        }
        
        return memo[i][j] = ans;
    }
};