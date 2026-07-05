class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int> ans;
        set<int> s(begin(nums), end(nums));

        for (auto it = rbegin(s); it != rend(s) and k; it++, k--) {
            ans.push_back(*it);
        }

        return ans;
    }
};