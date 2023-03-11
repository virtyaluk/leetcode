class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int lo = 0, hi = 0, n = size(nums), ans = 1;
        long long int cur = 0;
        
        sort(begin(nums), end(nums));
        
        while (hi < n) {
            cur += nums[hi];
            
            while (lo < hi and (long long int) nums[hi] * (hi - lo + 1) - cur > k) {
                cur -= nums[lo++];
            }
            
            ans = max(ans, hi - lo + 1);
            hi++;
        }
        
        return ans;
    }
};