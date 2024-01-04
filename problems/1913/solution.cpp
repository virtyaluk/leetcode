class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        return nums.back() * nums[size(nums) - 2] - nums[0] * nums[1];
    }
};