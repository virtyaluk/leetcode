class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};