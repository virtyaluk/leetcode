const int MOD = 1e9 + 7;

class Solution {
public:
    int kInversePairs(int n, int k) {
        if (n == 0) {
            return 0;
        }
        
        if (k == 0) {
            return 1;
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            long long int cumSum = 0;
            
            for (int j = 0; j <= k; j++) {
                if (not j) {
                    dp[i][j] = 1;
                    cumSum += 1;
                } else {
                    cumSum = (cumSum + dp[i - 1][j]);
                    
                    if (j - i >= 0) {
                        cumSum -= dp[i - 1][j - i];
                    }
                    
                    dp[i][j] = cumSum % MOD;
                }
            }
        }
        
        return dp[n][k];
    }
};