class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        vector<vector<int>> dp(k, vector<int>(k));

        for (int num: nums) {
            num %= k;

            for (int prev = 0; prev < k; prev++) {
                dp[prev][num] = dp[num][prev] + 1;
                ans = max(ans, dp[prev][num]);
            }
        }

        return ans;
    }
};