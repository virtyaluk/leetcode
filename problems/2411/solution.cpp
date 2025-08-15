class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = size(nums);
        vector<int> ans(n);
        vector<int> bits(31, -1);

        for (int i = n - 1; i >= 0; i--) {
            int j = i;

            for (int bit = 0; bit < 31; bit++) {
                if (not (nums[i] & (1 << bit))) {
                    if (bits[bit] != -1) {
                        j = max(j, bits[bit]);
                    }
                } else {
                    bits[bit] = i;
                }
            }

            ans[i] = j - i + 1;
        }

        return ans;
    }
};