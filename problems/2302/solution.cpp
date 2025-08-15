class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0,
            sum = 0;

        for (int lo = 0, hi = lo; hi < size(nums); hi++) {
            sum += nums[hi];

            while (lo <= hi && sum * (hi - lo + 1) >= k) {
                sum -= nums[lo++];
            }

            ans += hi - lo + 1;
        }

        return ans;
    }
};