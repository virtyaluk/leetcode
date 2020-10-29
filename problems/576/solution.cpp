typedef long long int ll;
const int MOD = 1e9 + 7;

class Solution {
public:
    int findPaths(int m, int n, int moves, int x, int y) {
        int ans = 0;
        vector<vector<ll>> dp(m, vector<ll>(n));
        dp[x][y] = 1;
        
        for (int move = 1; move <= moves; move++) {
            vector<vector<ll>> newDp(m, vector<ll>(n));
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (not i) {
                        ans = (ans + dp[i][j]) % MOD;
                    }
                    
                    if (not j) {
                        ans = (ans + dp[i][j]) % MOD;
                    }
                    
                    if (i == m - 1) {
                        ans = (ans + dp[i][j]) % MOD;
                    }
                    
                    if (j == n - 1) {
                        ans = (ans + dp[i][j]) % MOD;
                    }
                    
                    newDp[i][j] = (
                        (i > 0 ? dp[i - 1][j] : 0) +
                        (i < m - 1 ? dp[i + 1][j] : 0) +
                        (j > 0 ? dp[i][j - 1] : 0) +
                        (j < n - 1 ? dp[i][j + 1] : 0)
                    ) % MOD;
                }
            }
            
            dp = newDp;
        }
        
        return ans;
    }
    
    int findPaths1(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<ll>>> memo(m, vector<vector<ll>>(n, vector<ll>(maxMove + 1, -1)));
        return dfs(m, n, startRow, startColumn, maxMove, memo);
    }
    
    ll dfs(int m, int n, int x, int y, int moves, vector<vector<vector<ll>>>& memo) {
        if (x < 0 or y < 0 or x == m or y == n) {
            return 1;
        }
        
        if (moves == 0) {
            return 0;
        }
        
        if (memo[x][y][moves] >= 0) {
            return memo[x][y][moves];
        }
        
        return memo[x][y][moves] = (dfs(m, n, x + 1, y, moves - 1, memo)
            + dfs(m, n, x, y + 1, moves - 1, memo)
            + dfs(m, n, x - 1, y, moves - 1, memo)
            + dfs(m, n, x, y - 1, moves - 1, memo)) % MOD;
    }
};