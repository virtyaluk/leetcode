class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = size(nums1);
        vector<vector<int>> xorCalc(n, vector<int>(n));
        vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                xorCalc[i][j] = nums1[i] ^ nums2[j];
            }
        }

        return dfs(dp, xorCalc, 0, 0);
    }
    
    int dfs(
        vector<vector<int>>& dp,
        vector<vector<int>>& xorCalc,
        int i,
        int mask
    ) {
        if (i >= size(dp)) {
            return 0;
        }
        
        if (dp[i][mask] == INT_MAX) {
            for (int j = 0; j < size(dp); j++) {
                if (!(mask & (1 << j))) {
                    int newMask = mask | (1 << j);
                    
                    dp[i][mask] = min(dp[i][mask], xorCalc[i][j] + dfs(dp, xorCalc, i + 1, newMask));
                }
            }
        }
        
        return dp[i][mask];
    }
};