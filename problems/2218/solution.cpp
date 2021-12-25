class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = size(piles);
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        function<int(int, int)> dfs;
        
        dfs = [&](int i, int coins) {
            if (not i) {
                return 0;
            }
            
            if (dp[i][coins] == -1) {
                int curSum = 0;
                
                for (int curCoins = 0; curCoins <= min(coins, (int) size(piles[i - 1])); curCoins++) {
                    if (curCoins) {
                        curSum += piles[i - 1][curCoins - 1];
                    }
                    
                    dp[i][coins] = max(dp[i][coins], dfs(i - 1, coins - curCoins) + curSum);
                }
            }
            
            return dp[i][coins];
        };
        
        return dfs(n, k);
    }
};