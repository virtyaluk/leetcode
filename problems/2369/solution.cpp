class Solution {
private:
    bool dfs(vector<int>& nums, vector<int>& dp, int idx) {
        if (idx == size(nums)) {
            return true;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        if (idx + 1 < size(nums) and nums[idx] == nums[idx + 1]) {
            if (dfs(nums, dp, idx + 2)) {
                return true;
            }
            
            if (idx + 2 < size(nums) and nums[idx + 2] == nums[idx]) {
                if (dfs(nums, dp, idx + 3)) {
                    return true;
                }
            }
        }
        
        if (idx + 2 < size(nums) and nums[idx] == nums[idx + 1] - 1 and nums[idx] == nums[idx + 2] - 2) {
            if (dfs(nums, dp, idx + 3)) {
                return true;
            }
        }
        
        return dp[idx] = false;
    }
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(size(nums), -1);
        
        return dfs(nums, dp, 0);
    }
};