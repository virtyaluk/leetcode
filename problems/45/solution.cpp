class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, longestJump = 0, curEnd = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            longestJump = max(longestJump, i + nums[i]);
            
            if (curEnd == i) {
                ans++;
                curEnd = longestJump;
            }
        }
        
        return ans;
    }
    
    int jump2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, pow(10, 6));
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n) {
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
            }
        }
        
        return dp.back();
    }
    
    int jump1(vector<int>& nums) {
        unordered_map<int, int> memo;
        
        return helper(nums, memo, 0);
    }
    
    int helper(const vector<int>& nums, unordered_map<int, int>& memo, int idx) {
        if (idx == nums.size() - 1) {
            return 0;
        }
        
        // if (idx >= nums.size()) {
        //     return pow(10, 6);
        // }
        
        if (memo.count(idx)) {
            return memo[idx];
        }
        
        int jumps = pow(10, 6);
        
        for (int i = 1; i <= nums[idx]; i++) {
            if (idx + i < nums.size()) {
                jumps = min(jumps, helper(nums, memo, idx + i));
            }
        }
        
        return memo[idx] = jumps + 1;
    }
};