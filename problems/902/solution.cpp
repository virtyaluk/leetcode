class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int k = log10(n) + 1;
        string s = to_string(n);
        vector<int> dp(k + 1);
        dp[k] = 1;
        
        for (int i = k - 1; i >= 0; i--) {
            int si = s[i] - '0';
            
            for (string num: digits) {
                if (stoi(num) == si) {
                    dp[i] += dp[i + 1];
                } else if (stoi(num) < si) {
                    dp[i] += pow(digits.size(), k - i - 1);
                }
            }
        }
        
        for (int i = 1; i < k; i++) {
            dp[0] += pow(digits.size(), i);
        }
        
        return dp[0];
    }
};