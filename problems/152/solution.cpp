class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], maxSoFar = nums[0], minSoFar = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int cur = nums[i];
            
            int tmp = max({cur, maxSoFar * cur, minSoFar * cur});
            minSoFar = min({cur, maxSoFar * cur, minSoFar * cur});
            
            maxSoFar = tmp;
            ans = max(ans, maxSoFar);
        }
        
        return ans;
    }
};