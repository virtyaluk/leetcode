class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;

        for (int lo = 0, hi = 0, cur = 0; hi < size(nums); hi++) {
            while (cur & nums[hi]) {
                cur ^= nums[lo++];
            }

            cur |= nums[hi];
            ans = max(ans, hi - lo + 1);
        }

        return ans;
    }
};