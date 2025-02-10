class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 0;
        
        sort(begin(nums), end(nums));
        
        for (int lo = 0, hi = 0; lo < size(nums); lo++) {
            while (hi < size(nums) and nums[hi] - nums[lo] <= 2 * k) {
                hi++;
            }
            
            ans = max(hi - lo, ans);
        }
        
        return ans;
    }
};