class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = size(nums);
        long long ans = 0;
        unordered_map<int, int> um;

        for (int lo = 0, hi = -1, cur = 0; lo < n; lo++) {
            while (cur < k and hi + 1 < n) {
                hi++;
                cur += um[nums[hi]];
                um[nums[hi]]++;
            }

            if (cur >= k) {
                ans += n - hi;
            }

            um[nums[lo]]--;
            cur -= um[nums[lo]];
        }

        return ans;
    }
};