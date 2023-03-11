class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = 0, lo = 0, hi = size(nums) - 1;
        
        sort(begin(nums), end(nums));
        
        while (lo < hi) {
            ans = max(ans, nums[lo++] + nums[hi--]);
        }
        
        return ans;
    }
};