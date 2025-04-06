class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < size(nums) - 1; i++) {
            ans.push_back(nums[i] | nums[i + 1]);
        }

        return ans;
    }
};