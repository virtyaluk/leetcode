class Solution {
public:
    double new21Game(int n, int k, int w) {
        if (not k or n >= k + w) {
            return 1;
        }
        
        double ans = 0.0, sum = 1.0;
        vector<double> dp(n + 1);
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = sum / w;
            
            if (i < k) {
                sum += dp[i];
            } else {
                ans += dp[i];
            }
            
            if (i - w >= 0) {
                sum -= dp[i - w];
            }
        }
        
        return ans;
    }
};