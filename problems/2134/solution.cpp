class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans = INT_MAX,
            ones = accumulate(begin(nums), end(nums), 0);
        
        for (int lo = 0, cur = nums.front(), hi = 0; lo < size(nums); lo++) {
            if (lo) {
                cur -= nums[lo - 1];
            }
            
            while (hi - lo + 1 < ones) {
                hi++;
                cur += nums[hi % size(nums)];
            }
            
            ans = min(ans, ones - cur);
        }
        
        return ans;
    }
};