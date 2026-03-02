class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = size(nums),
            ans = n;
        
        sort(begin(nums), end(nums));

        for (int lo = 0, hi = 0; lo < n; lo++) {
            while (hi < n and nums[hi] <= static_cast<long long>(nums[lo]) * k) {
                hi++;
            }

            ans = min(ans, n - (hi - lo));
        }

        return ans;
    }
};