class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int lo = 0, hi = size(nums) - 1;
        
        while (nums[lo] + nums[hi] != target) {
            if (nums[lo] + nums[hi] < target) {
                lo++;
            } else {
                hi--;
            }
        }
        
        return {lo + 1, hi + 1};
    }
};