class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        
        if (nums.empty()) {
            ans.push_back({lower, upper});
            
            return ans;
        }
        
        if (lower < nums.front()) {
            ans.push_back({lower, nums.front() - 1});
        }
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] > 1) {
                ans.push_back({nums[i - 1] + 1, nums[i] - 1});
            }
        }
        
        if (upper > nums.back()) {
            ans.push_back({nums.back() + 1, upper});
        }
        
        return ans;
    }
};