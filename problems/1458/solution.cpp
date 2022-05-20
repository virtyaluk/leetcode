class Solution {
private:    
    int dfs(vector<vector<int>>& dp, const vector<int>& nums1, const vector<int>& nums2, int i, int j) {
        if (i == size(nums1) or j == size(nums2)) {
            return INT_MIN;
        }
        
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        
        int a = nums1[i] * nums2[j],
            b = dfs(dp, nums1, nums2, i + 1, j + 1) == INT_MIN ? INT_MIN : dfs(dp, nums1, nums2, i + 1, j + 1) + nums1[i] * nums2[j],
            c = dfs(dp, nums1, nums2, i + 1, j),
            d = dfs(dp, nums1, nums2, i, j + 1);
        
        return dp[i][j] = max({a, b, c, d});
    }

public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = size(nums1),
            n = size(nums2);
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        return dfs(dp, nums1, nums2, 0, 0);
    }
};