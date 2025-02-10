class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for (int i = size(nums) - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            } else if (__builtin_popcount(nums[i]) == __builtin_popcount(nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
            } else {
                return false;
            }
        }
        
        for (int i = 0; i < size(nums) - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            } else if (__builtin_popcount(nums[i]) == __builtin_popcount(nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
            } else {
                return false;
            }
        }
        
        return true;
    }
};