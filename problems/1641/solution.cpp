class Solution {
public:
    int countVowelStrings(int n) {
        // return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
        
        int dp[] = {0, 1, 2, 3, 4, 5};
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                dp[j] += dp[j - 1];
            }
        }
        
        return dp[5];
    }
};