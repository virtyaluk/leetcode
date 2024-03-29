class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (const int& coin: coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};