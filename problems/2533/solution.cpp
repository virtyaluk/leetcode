const int MOD = 1e9 + 7;

class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        vector<long long int> dp(maxLength + 1);
        
        for (int i = maxLength; i >= 0; i--) {
            if (i >= minLength) {
                dp[i]++;
            }
            
            if (i + oneGroup <= maxLength) {
                dp[i] = (dp[i] + dp[i + oneGroup]) % MOD;
            }
            
            if (i + zeroGroup <= maxLength) {
                dp[i] = (dp[i] + dp[i + zeroGroup]) % MOD;
            }
        }
        
        return dp.front();
    }
};