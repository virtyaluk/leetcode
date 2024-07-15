class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        vector<int> ans;
        
        for (int i = 1; i < size(nums) - 1; i++) {
            if (nums[i] > nums[i - 1] and nums[i] > nums[i + 1]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};