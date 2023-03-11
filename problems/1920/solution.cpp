class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int i = 0; i < size(nums); i++) {
            ans.push_back(nums[nums[i]]);
        }
        
        return ans;
    }
};