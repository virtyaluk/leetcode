class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(size(nums));
        
        for (int i = 0, j = 1, k = 0; k < size(nums); k++) {
            if (nums[k] >= 0) {
                ans[i] = nums[k];
                i += 2;
            } else {
                ans[j] = nums[k];
                j += 2;
            }
        }
        
        return ans;
    }
};