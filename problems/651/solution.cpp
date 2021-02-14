class Solution {
public:
    int maxA(int n) {
        vector<int> dp(max(7, n + 1));
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 4;
        dp[5] = 5;
        
        for (int i = 6; i <= n; i++) {
            dp[i] = max({
                dp[i - 1] + 1, // print a
                2 * dp[i - 3],
                3 * dp[i - 4],
                4 * dp[i - 5]
            });
        }
        
        return dp[n];
    }
};