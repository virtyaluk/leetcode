class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int ans = INT_MAX;
        
        sort(begin(nums), end(nums));
        
        for (int lo = 0, hi = size(nums) - 1; lo < hi; lo++, hi--) {
            ans = min(ans, nums[lo] + nums[hi]);
        }
        
        return (double) ans / 2;
    }
};