class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<double> dp(target + 1);
        dp[0] = 1.0;
        
        for (int i = 0; i < size(prob); i++) {
            for (int j = min(i + 1, target); j >= 0; j--) {
                dp[j] = (j ? dp[j - 1] : 0) * prob[i] + dp[j] * (1 - prob[i]);
            }
        }
        
        return dp[target];
    }
};