class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans(begin(nums), end(nums));

        ans.insert(end(ans), rbegin(nums), rend(nums));

        return ans;
    }
};