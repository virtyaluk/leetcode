class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        
        int lo = 0,
            hi = nums.back() - nums.front(),
            n = size(nums);
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2,
                cnt = 0;
            
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n and nums[i] - nums[j] > mid) {
                    j++;
                }
                
                cnt += (i - j);
            }
            
            if (cnt >= k) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};