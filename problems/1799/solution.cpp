class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<vector<int>> dp(size(nums) + 1, vector<int>(1 << size(nums), -1));
        
        return dfs(dp, nums, 0, 0);
    }
    
    int dfs(vector<vector<int>>& dp, vector<int>& nums, int idx, int mask) {
        int n = size(nums);
        
        if (idx == n / 2) {
            return 0;
        }
        
        if (dp[idx][mask] != -1) {
            return dp[idx][mask];
        }
        
        int ans = 0;
        
        for (int x = 0; x < n; x++) {
            for (int y = x + 1; y < n; y++) {
                if ((mask & (1 << x)) == 0 and (mask & (1 << y)) == 0) {
                    int newMask = mask | (1 << x);
                    newMask |= (1 << y);
                    
                    ans = max(ans, (idx + 1) * gcd(nums[x], nums[y]) + dfs(dp, nums, idx + 1, newMask));
                }
            }
        }
        
        return dp[idx][mask] = ans;
    }
};