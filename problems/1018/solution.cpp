class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(size(nums));

        for (int i = 0, pref = 0; i < size(nums); i++) {
            pref = (pref * 2 + nums[i]) % 5;
            ans[i] = not pref;
        }

        return ans;
    }
};