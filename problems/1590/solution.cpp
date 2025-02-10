class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = size(nums),
            totalSum = 0,
            ans = n,
            target = 0;
        unordered_map<int, int> um;
        um[0] = -1;
        
        for (const int& num: nums) {
            totalSum = (totalSum + num) % p;
        }
        
        target = totalSum % p;
        
        if (not target) {
            return 0;
        }
        
        for (int i = 0, curSum = 0; i < n; i++) {
            curSum = (curSum + nums[i]) % p;
            int needed = (curSum - target + p) % p;
            
            if (um.find(needed) != end(um)) {
                ans = min(ans, i - um[needed]);
            }
            
            um[curSum] = i;
        }
        
        return ans == n ? -1 : ans;
    }
};