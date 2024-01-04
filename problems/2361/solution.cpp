class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = size(regular);
        vector<long long> ans;
        vector<vector<long long>> dp(n + 1, vector<long long>(2));
        
        dp[0][0] = 0; // regular lane
        dp[0][1] = expressCost; // express lane
        
        for (int i = 1; i <= n; i++) {
            dp[i][0] = regular[i - 1] + min(dp[i - 1][0], dp[i - 1][1]); // regular
            dp[i][1] = express[i - 1] + min(dp[i - 1][0] + expressCost, dp[i - 1][1]); // express
            ans.push_back(min(dp[i][0], dp[i][1]));
        }
        
        return ans;
    }
};