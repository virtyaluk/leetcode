class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        unordered_set<int> banned;
        
        for (const vector<int>& mine: mines) {
            banned.insert(mine[0] * 10000 + mine[1]);
        }
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            
            for (int j = 0; j < n; j++) {
                count = banned.count(i * 10000 + j) ? 0 : count + 1;
                dp[i][j] = count;
            }
            
            count = 0;
            
            for (int j = n - 1; j >= 0; j--) {
                count = banned.count(i * 10000 + j) ? 0 : count + 1;
                dp[i][j] = min(dp[i][j], count);
            }
        }
        
        for (int j = n - 1; j >= 0; j--) {
            int count = 0;
            
            for (int i = 0; i < n; i++) {
                count = banned.count(i * 10000 + j) ? 0 : count + 1;
                dp[i][j] = min(dp[i][j], count);
            }
            
            count = 0;
            
            for (int i = n - 1; i >= 0; i--) {
                count = banned.count(i * 10000 + j) ? 0 : count + 1;
                dp[i][j] = min(dp[i][j], count);
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};