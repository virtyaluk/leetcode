class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums.front();
        
        for (int i = 1, cur = nums.front(); i < size(nums); i++) {
            if (nums[i] > nums[i - 1]) {
                cur += nums[i];
            } else {
                cur = nums[i];
            }
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};