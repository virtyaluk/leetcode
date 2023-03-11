const int MOD = 1e9 + 7;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        int ans = 0;
        dp.front() = 1;
        
        for (int i = 1; i <= high; i++) {
            if (i >= zero) {
                dp[i] += dp[i - zero];
            }
            
            if (i >= one) {
                dp[i] += dp[i - one];
            }
            
            dp[i] %= MOD;
        }
        
        for (int i = low; i <= high; i++) {
            ans += dp[i];
            ans %= MOD;
        }
        
        return ans;
    }
};