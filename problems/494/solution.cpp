class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[nums[0]]++;
        dp[-nums[0]]++;
        
        for (int i = 1; i < size(nums); i++) {
            unordered_map<int, int> newDp;
            
            for (auto [sum, count]: dp) {
                newDp[sum + nums[i]] += count;
                newDp[sum - nums[i]] += count;
            }
            
            dp = newDp;
        }
        
        return dp[target];
    }
    
    int findTargetSumWays1(vector<int>& nums, int target) {
        int n = size(nums);
        vector<unordered_map<int, int>> dp(n);
        dp[0][nums[0]]++;
        dp[0][-nums[0]]++;
        
        for (int i = 1; i < n; i++) {
            for (auto [sum, count]: dp[i - 1]) {
                dp[i][sum + nums[i]] += count;
                dp[i][sum - nums[i]] += count;
            }
        }
        
        return dp.back()[target];
    }
};
