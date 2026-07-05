class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> us(begin(nums), end(nums));

        sort(begin(nums), end(nums));

        for (int i = nums.front() + 1; i < nums.back(); i++) {
            if (not us.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};