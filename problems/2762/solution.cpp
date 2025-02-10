class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0,
            winLen = 0;
        
        int lo = 0,
            hi = 0,
            m = nums.front(),
            M = nums.front();
        
        for (; hi < size(nums); hi++) {
            m = min(m, nums[hi]);
            M = max(M, nums[hi]);
            
            if (M - m > 2) {
                winLen = hi - lo;
                ans += (winLen * (winLen + 1) / 2);
                lo = hi;
                m = M = nums[hi];
                
                while (lo > 0 and abs(nums[hi] - nums[lo - 1]) <= 2) {
                    lo--;
                    m = min(m, nums[lo]);
                    M = max(M, nums[lo]);
                }
                
                if (lo < hi) {
                    winLen = hi - lo;
                    ans -= (winLen * (winLen + 1) / 2);
                }
            }
        }
        
        winLen = hi - lo;
        ans += (winLen * (winLen + 1) / 2);
        
        return ans;
    }
};