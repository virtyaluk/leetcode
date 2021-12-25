const int MOD = 1000000007;

class Solution {
public:
    int numRollsToTarget(int d, int face, int target) {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        
        for (int i = 1; i <= d; i++) {
            for (int j = 0; j <= target; j++) {
                for (int f = 1; f <= face; f++) {
                    if (j >= f) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - f]) % MOD;
                    } else {
                        break;
                    }
                }
            }
        }
        
        return dp[d][target];
    }
};