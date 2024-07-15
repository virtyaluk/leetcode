class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> um;
        
        for (int lo = 0, hi = 0; hi < size(nums); hi++) {
            um[nums[hi]]++;
            
            while (lo < hi and um[nums[hi]] > k) {
                um[nums[lo++]]--;
            }
            
            ans = max(ans, hi - lo + 1);
        }
        
        return ans;
    }
};