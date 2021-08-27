class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) {
            return 1;
        }
        
        vector<vector<double>> dp(200, vector<double>(200));
        function<double(int, int)> dfs;
        dfs = [&](int a, int b) -> double {
            if (a <= 0 and b <= 0) {
                return 0.5;
            }
            
            if (a <= 0) {
                return 1;
            }
            
            if (b <= 0) {
                return 0;
            }
            
            if (dp[a][b] > 0) {
                return dp[a][b];
            }
            
            return dp[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) + dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
        };
        
        return dfs((n + 24) / 25, (n + 24) / 25);
    }
};