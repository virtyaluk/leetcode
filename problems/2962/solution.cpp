class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int maxEl = *max_element(begin(nums), end(nums)),
            curCount = 0;
        
        for (int lo = 0, hi = 0; hi < size(nums); hi++) {
            curCount += nums[hi] == maxEl;
            
            while (curCount >= k) {
                curCount -= nums[lo++] == maxEl;
            }
            
            ans += lo;
        }
        
        return ans;
    }
};