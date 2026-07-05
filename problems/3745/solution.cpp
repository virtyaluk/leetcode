class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(begin(nums), end(nums));

        return nums.back() + nums[size(nums) - 2] - nums.front();
    }
};