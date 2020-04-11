class Solution {
public:
    int numTrees(int n) {
        long long int c = 1;
        
        for (int i = 0; i < n; i++) {
            c = c * 2 * (2 * i + 1) / (i + 2);
        }
        
        return c;
    }
    
    int numTrees1(int n) {
        vector<int> dp(n + 1);
        
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};