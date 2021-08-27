class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = nums.size() - 1, lo = 0, hi = nums.size() - 1;
        
        while (lo <= hi) {
            if (abs(nums[lo]) > abs(nums[hi])) {
                ans[i--] = pow(nums[lo++], 2);
            } else {
                ans[i--] = pow(nums[hi--], 2);
            }
        }
        
        return ans;
    }
};