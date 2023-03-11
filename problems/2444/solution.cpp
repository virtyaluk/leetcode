class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = size(nums),
            lastMinK = -1,
            lastMaxK = -1,
            lo = 0,
            hi = 0;
        
        while (hi < n) {
            while (hi < n) {
                if (nums[hi] < minK or nums[hi] > maxK) {
                    break;
                }
                
                if (nums[hi] == minK) {
                    lastMinK = hi;
                }
                
                if (nums[hi] == maxK) {
                    lastMaxK = hi;
                }
                
                if (lastMinK != -1 and lastMaxK != -1) {
                    ans += min(lastMinK, lastMaxK) - lo + 1;
                }
                
                hi++;
            }
            
            hi++;
            lo = hi;
            lastMinK = -1;
            lastMaxK = -1;
        }
        
        return ans;
    }
};