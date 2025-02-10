class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        
        for (int i = 0, j = -1; i < size(nums); i++) {
            if (i > 0 and nums[i] != nums[i - 1] + 1) {
                j = i;
            }
            
            if (i >= k - 1) {
                if (i - j >= k - 1) {
                    ans.push_back(nums[i]);
                } else {
                    ans.push_back(-1);
                }
            }
        }
        
        return ans;
    }
};