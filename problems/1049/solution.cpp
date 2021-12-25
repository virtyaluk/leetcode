class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        vector<bool> dp(1501);
        
        dp[0] = true;
        
        for (const int& stone: stones) {
            sum += stone;
            
            for (int i = min(1500, sum); i >= stone; i--) {
                dp[i] = dp[i] || dp[i - stone];
            }
        }
        
        for (int i = sum / 2; i >= 0; i--) {
            if (dp[i]) {
                return sum - 2 * i;
            }
        }
        
        return 0;
    }
};