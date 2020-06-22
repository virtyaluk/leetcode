class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> newNums(n);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < nums.size(); i++) {
            newNums[i + 1] = nums[i];
        }
        
        newNums[0] = newNums[n - 1] = 1;
        
        return helper(dp, newNums, 0, n - 1);
    }
    
    int helper(vector<vector<int>>& dp, vector<int>& nums, int left, int right) {
        if (left + 1 == right) {
            return 0;
        }
        
        if (dp[left][right] > 0) {
            return dp[left][right];
        }
        
        int ans = 0;
        
        for (int i = left + 1; i < right; i++) {
            ans = max(ans, nums[left] * nums[i] * nums[right] + helper(dp, nums, left, i) + helper(dp, nums, i, right));
        }
        
        dp[left][right] = ans;
        
        return ans;
    }
};