class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(begin(nums) + 1, end(nums));
        
        return nums[0] + nums[1] + nums[2];
    }
};