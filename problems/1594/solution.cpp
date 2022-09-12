class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mod = 1000000000+7;
        vector<vector<pair<long, long>>> dp(m, vector<pair<long, long>>(n));
        
        long p = 1;
        
        for (int i = 0; i < m; i++) {
            p *= grid[i][0];
            dp[i][0].first = dp[i][0].second = p;
        }
        
        p = 1;
        
        for (int j = 0; j < n; j++) {
            p *= grid[0][j];
            dp[0][j].first = dp[0][j].second = p;
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long x = grid[i][j] * max(dp[i - 1][j].first, dp[i][j - 1].first);
                long y = grid[i][j] * min(dp[i - 1][j].second, dp[i][j - 1].second);
                
                dp[i][j].first = max(x, y);
                dp[i][j].second = min(x, y);
            }
        }
        
        return dp.back().back().first < 0 ? -1 : dp.back().back().first % mod;
    }
};