class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 1; i < size(nums); i++) {
            if (nums[i] <= nums[i - 1]) {
                ans += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;            }
        }
        
        return ans;
    }
};