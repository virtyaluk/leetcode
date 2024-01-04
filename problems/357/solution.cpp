class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(9, 0);
        dp[0] = 1;
        dp[1] = 10;
        
        for (int i = 2, p = 9, j = 9; i <= n; i++) {
            p *= j;
            j--;
            dp[i] = dp[i - 1] + p;
        }
        
        return dp[n];
    }
};