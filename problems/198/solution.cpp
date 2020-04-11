class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        int i2 = 0, i1 = nums[0];
        
        for (int i = 2; i <= nums.size(); i++) {
            int tmp = i1;
            i1 = max(i1, i2 + nums[i - 1]);
            i2 = tmp;
        }
        
        return i1;
        
//         vector<int> dp(nums.size() + 1);
//         dp[0] = 0;
//         dp[1] = nums[0];
        
//         for (int i = 2; i <= nums.size(); i++) {
//             dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
//         }
        
//         return dp[nums.size()];
    }
};