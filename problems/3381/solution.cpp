class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long n = size(nums),
            ans = LONG_LONG_MIN,
            prefSum = 0;
        vector<long long> ksum(k, LONG_LONG_MAX / 2);
        ksum.back() = 0;

        for (int i = 0; i < n; i++) {
            prefSum += nums[i];
            ans = max(ans, prefSum - ksum[i % k]);
            ksum[i % k] = min(ksum[i % k], prefSum);
        }

        return ans;
    }
};