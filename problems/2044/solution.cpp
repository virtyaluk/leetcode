class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;
        vector<int> dp(1 << 17, 0);
        
        dp.front() = 1;
        
        for (const int& num: nums) {
            for (int i = max; i >= 0; i--) {
                dp[i | num] += dp[i];
            }
            
            max |= num;
        }
        
        return dp[max];
    }
};