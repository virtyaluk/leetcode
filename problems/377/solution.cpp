typedef unsigned int uint;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target + 1);
        dp[0] = 1;
        
        for (int i = 1; i <= target; i++) {
            for (const int& num: nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }

    int combinationSum41(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        
        return helper(nums, target, memo);
    }
    
    int helper(const vector<int>& nums, int target, unordered_map<int, int>& memo) {
        if (target == 0) {
            return 1;
        }
        
        if (memo.count(target)) {
            return memo[target];
        }
        
        int cur = 0;
        
        for (const int& num: nums) {
            if (target >= num) {
                cur += helper(nums, target - num, memo);
            }
        }
        
        return memo[target] = cur;
    }
};