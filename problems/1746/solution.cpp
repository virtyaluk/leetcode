class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int ans = 0, n = size(nums);
        vector<int> rightMax(n + 1);
        
        for (int i = n - 1; i >= 0; i--) {
            rightMax[i] = max(0, nums[i] + rightMax[i + 1]);
        }
        
        for (int i = 0, leftMax = 0; i < n; i++) {
            ans = max(ans, leftMax + nums[i] * nums[i] + rightMax[i + 1]);
            leftMax = max(0, nums[i] + leftMax);
        }
        
        return ans;
    }
};