class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> ans(size(nums), 1);

        fill_n(begin(ans), count_if(begin(nums), end(nums), [](int a) { return a % 2 == 0; }), 0);

        return ans;
    }
};