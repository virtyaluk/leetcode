class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n < 2 || k == 0) return 0;

        vector<vector<long long>> dp(k + 1, vector<long long>(3, 0));

        for (int t = 0; t <= k; ++t) {
            dp[t][0] = 0;
            dp[t][1] = -prices[0];      // buy stock
            dp[t][2] = prices[0];       // short sell
        }

        for (int i = 1; i < n; ++i) {
            vector<vector<long long>> new_dp = dp;

            for (int t = 1; t <= k; ++t) {
                new_dp[t][0] = max({dp[t][0], dp[t][1] + prices[i], dp[t][2] - prices[i]});
                new_dp[t][1] = max(dp[t][1], dp[t - 1][0] - prices[i]);
                new_dp[t][2] = max(dp[t][2], dp[t - 1][0] + prices[i]);
            }

            dp = move(new_dp);
        }

        long long maxProfit = 0;
        for (int t = 0; t <= k; ++t) {
            maxProfit = max(maxProfit, dp[t][0]);
        }

        return maxProfit;
    }
};