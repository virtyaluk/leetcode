class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = size(nums),
            e = 0,
            o = 0;
        vector<int> ans(n);

        for (const int& num: nums) {
            if (num & 1) {
                o++;
            } else {
                e++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                o--;
                ans[i] = e;
            } else {
                e--;
                ans[i] = o;
            }
        }

        return ans;
    }
};