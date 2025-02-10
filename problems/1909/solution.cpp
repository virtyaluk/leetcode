class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 1; i < size(nums); i++) {
            if (nums[i - 1] >= nums[i]) {
                ans++;
                
                if (i > 1 && nums[i - 2] >= nums[i]) {
                    nums[i] = nums[i - 1];
                }
            }
        }
        
        return ans < 2;
    }
};