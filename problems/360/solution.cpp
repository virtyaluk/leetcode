class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ans(size(nums));
        int lo = 0, hi = size(nums) - 1, ilo = 0, ihi = size(nums) - 1;
        function<int(int)> fn = [&](int x) {
            return a * x * x + b * x + c;
        };
        
        while (lo <= hi) {
            int lofn = fn(nums[lo]),
                hifn = fn(nums[hi]);
            
            if (a >= 0) {
                if (lofn > hifn) {
                    ans[ihi--] = lofn;
                    lo++;
                } else {
                    ans[ihi--] = hifn;
                    hi--;
                }
            } else {
                if (lofn < hifn) {
                    ans[ilo++] = lofn;
                    lo++;
                } else {
                    ans[ilo++] = hifn;
                    hi--;
                }
            }
        }
        
        return ans;
    }
};