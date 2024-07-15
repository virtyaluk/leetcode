class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        
        for (int lo = 0, hi = 0, cur = 0, preZeros = 0; hi < size(nums); hi++) {
            cur += nums[hi];
            
            while (lo < hi and (nums[lo] == 0 or cur > goal)) {
                if (nums[lo]) {
                    preZeros = 0;
                } else {
                    preZeros++;
                }
                
                cur -= nums[lo++];
            }
            
            if (cur == goal) {
                ans += 1 + preZeros;
            }
        }
        
        return ans;
    }
};