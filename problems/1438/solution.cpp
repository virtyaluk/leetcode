class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        multiset<int> ms;
        
        for (int lo = 0, hi = 0; hi < size(nums); hi++) {
            ms.insert(nums[hi]);
            
            while (*rbegin(ms) - *begin(ms) > limit) {
                ms.erase(ms.find(nums[lo++]));
            }
            
            ans = max(ans, hi - lo + 1);
        }
        
        return ans;
    }
};