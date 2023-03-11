class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = size(questions);
        vector<long long> dp(n);
        
        dp.back() = questions.back().front();
        
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = questions[i].front();
            
            if (i + questions[i].back() + 1 < n) {
                dp[i] += dp[i + questions[i].back() + 1];
            }
            
            dp[i] = max(dp[i], dp[i + 1]);
        }
        
        return dp.front();
    }
};