class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        if (nums.front() + nums[1] <= nums.back()) {
            return "none";
        }
        
        if (nums.front() == nums[1] and nums[1] == nums.back()) {
            return "equilateral";
        }
        
        if (nums.front() == nums[1] or nums[1] == nums.back()) {
            return "isosceles";
        }
        
        return "scalene";
    }
};