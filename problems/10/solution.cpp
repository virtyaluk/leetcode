class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = size(s), np = size(p);
        vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1));
        dp[0][0] = true;
        
        for (int i = 0; i <= ns; i++) {
            for (int j = 1; j <= np; j++) {
                // if (p[j - 1] == '*') {
                //     if (i and (p[j - 2] == s[i - 1] or p[j - 2] == '.')) {
                //         dp[i][j] = dp[i - 1][j];
                //     } else {
                //         dp[i][j] = dp[i][j - 2];
                //     }
                // } else if (i and (p[j - 1] == '.' or p[j - 1] == s[i - 1])){
                //     dp[i][j] = dp[i - 1][j - 1];
                // }
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] or (i and (p[j - 2] == s[i - 1] or p[j - 2] == '.') and dp[i - 1][j]);
                } else {
                    dp[i][j] = i and dp[i - 1][j - 1] and (p[j - 1] == '.' or p[j - 1] == s[i - 1]);
                }
            }
        }
        
        return dp.back().back();
    }
    
    bool isMatch2(string s, string p) {
        int ns = size(s), np = size(p);
        vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1));
        dp[0][0] = true;
        
        for (int j = 2; j <= np; j++) {
            dp[0][j] = p[j - 1] == '*' and dp[0][j - 2];
        }
        
        for (int j = 1; j <= np; j++) {
            for (int i = 1; i <= ns; i++) {
                if (s[i - 1] == p[j - 1] or p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] or ((s[i - 1] == p[j - 2] or p[j - 2] == '.') and dp[i - 1][j]);
                }
            }
        }
        
        return dp[ns][np];
    }
    
    bool isMatch1(string s, string p) {
        if (empty(p)) {
            return empty(s);
        }
        
        bool firstMatch = not empty(s) and (p[0] == s[0] or p[0] == '.');
        
        if (size(p) >= 2 and p[1] == '*') {
            return isMatch(s, p.substr(2)) or (firstMatch and isMatch(s.substr(1), p));
        }
        
        return firstMatch and isMatch(s.substr(1), p.substr(1));
    }
};

/*
  . c * a * b
. t f t f t f
a f f f t 
a
b


*/