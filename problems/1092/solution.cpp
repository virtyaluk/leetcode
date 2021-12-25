class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        int i = 0, j = 0;
        
        for (const char& ch: LCS(str1, str2)) {
            while (str1[i] != ch) {
                ans.push_back(str1[i++]);
            }
            
            while (str2[j] != ch) {
                ans.push_back(str2[j++]);
            }
            
            ans.push_back(ch);
            i++, j++;
        }
        
        return ans + str1.substr(i) + str2.substr(j);
    }
    
    string LCS(string& a, string& b) {
        int m = size(a), n = size(b);
        vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i] == b[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + a[i];
                } else {
                    dp[i + 1][j + 1] = size(dp[i + 1][j]) > size(dp[i][j + 1]) ? dp[i + 1][j] : dp[i][j + 1];
                }
            }
        }
        
        return dp.back().back();
    }
};