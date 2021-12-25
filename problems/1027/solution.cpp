class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = size(nums),
            ans = 1;
        vector<vector<int>> dp(n + 1, vector<int>(1001, 1));
        
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int dif = nums[i] - nums[j] + 500;
                dp[i + 1][dif] = max(dp[i + 1][dif], 1 + dp[j + 1][dif]);
                ans = max(ans, dp[i + 1][dif]);
            }
        }
        
        return ans;
    }
};