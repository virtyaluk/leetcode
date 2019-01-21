class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        
        for (int i = 1; i < m; i++) {
            vector<int> newDp(n, 1);
            
            for (int j = 1; j < n; j++) {
                newDp[j] = newDp[j - 1] + dp[j];
            }
            
            dp = newDp;
        }
        
        return dp.back();
    }
};