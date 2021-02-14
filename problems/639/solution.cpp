const int MOD = 1e9 + 7;

class Solution {
public:
    int numDecodings(string s) {
        int n = size(s);
        long long int dp1 = 1, dp2 = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp2 = dp1;
                dp1 = 0;
                continue;
            }

            long long int dp = 0;
            
            if (s[i] == '*') {
                // *
                dp += 9 * dp1;
                
                if (i + 1 < n) {
                    // *n
                    if (isdigit(s[i + 1])) {
                        dp += dp2;
                        
                        if (s[i + 1] <= '6') {
                            dp += dp2;
                        }
                    } else if (s[i + 1] == '*') {
                        // **
                        dp += 15 * dp2;
                    }
                }
            } else {
                // n
                dp += dp1;
                
                if (i + 1 < n) {
                    // nn
                    if (isdigit(s[i + 1])) {
                        int num = stoi(s.substr(i, 2));
                        
                        if (num > 0 and num <= 26) {
                            dp += dp2;
                        }
                    } else if (s[i + 1] == '*') {
                        // n*
                        if (s[i] == '1') {
                            dp += 9 * dp2;
                        } else if (s[i] == '2') {
                            dp += 6 * dp2;
                        }
                    }
                }
            }
            
            dp2 = dp1;
            dp1 = dp % MOD;
        }
        
        return dp1;
    }
    
    int numDecodings1(string s) {
        int n = size(s);
        vector<long long int> dp(n + 1);
        dp[n] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                continue;
            }

            
            if (s[i] == '*') {
                // *
                dp[i] += 9 * dp[i + 1];
                
                if (i + 1 < n) {
                    // *n
                    if (isdigit(s[i + 1])) {
                        dp[i] += dp[i + 2];
                        
                        if (s[i + 1] <= '6') {
                            dp[i] += dp[i + 2];
                        }
                    } else if (s[i + 1] == '*') {
                        // **
                        dp[i] += 15 * dp[i + 2];
                    }
                }
            } else {
                // n
                dp[i] += dp[i + 1];
                
                if (i + 1 < n) {
                    // nn
                    if (isdigit(s[i + 1])) {
                        int num = stoi(s.substr(i, 2));
                        
                        if (num > 0 and num <= 26) {
                            dp[i] += dp[i + 2];
                        }
                    } else if (s[i + 1] == '*') {
                        // n*
                        if (s[i] == '1') {
                            dp[i] += 9 * dp[i + 2];
                        } else if (s[i] == '2') {
                            dp[i] += 6 * dp[i + 2];
                        }
                    }
                }
            }
            
            dp[i] = dp[i] % MOD;
        }
        
        return dp[0];
    }
};