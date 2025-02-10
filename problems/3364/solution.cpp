class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX,
            n = size(nums);
        
        for (int lo = 0; lo < n; lo++) {
            for (int hi = lo, cur = 0; hi < n; hi++) {
                cur += nums[hi];
                int len = hi - lo + 1;
                
                if (len >= l and len <= r and cur > 0) {
                    ans = min(ans, cur);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};