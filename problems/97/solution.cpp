class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        
        vector<bool> dp(s2.size() + 1);
        
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                if (not i and not j) {
                    dp[j] = true;
                } else if (not i) {
                    dp[j] = dp[j - 1] and s3[j - 1] == s2[j - 1];
                } else if (not j) {
                    dp[j] = dp[j] and s3[i - 1] == s1[i - 1];
                } else {
                    dp[j] = (dp[j - 1] and s2[j - 1] == s3[i + j - 1])
                        or (dp[j] and s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        
        return dp.back();
    }
    
    bool isInterleave3(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1));
        dp[0][0] = true;
        
        for (int j = 1; j <= s2.size(); j++) {
            dp[0][j] = dp[0][j - 1] and s3[j - 1] == s2[j - 1];
        }
        
        for (int i = 1; i <= s1.size(); i++) {
            dp[i][0] = dp[i - 1][0] and s3[i - 1] == s1[i - 1];
        }
        
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                dp[i][j] = (dp[i][j - 1] and s2[j - 1] == s3[i + j - 1])
                    or (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]);
            }
        }
        
        return dp.back().back();
    }
    
    bool isInterleave2(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        
        vector<vector<int>> m(s1.size(), vector<int>(s2.size(), -1));
        
        return helper(s1, s2, s3, 0, 0, 0, m);
    }
    
    bool helper(const string& s1, const string& s2, const string& s3, int i, int j, int k, vector<vector<int>>& m) {
        if (i >= s1.size()) {
            return s2.substr(j) == s3.substr(k);
        }
        
        if (j >= s2.size()) {
            return s1.substr(i) == s3.substr(k);
        }
        
        if (m[i][j] != -1) {
            return m[i][j] == 1;
        }
        
        bool ans = false;
        
        if (s1[i] == s3[k]) {
            ans = ans || helper(s1, s2, s3, i + 1, j, k + 1, m);
        }
        
        if (s2[j] == s3[k]) {
            ans = ans || helper(s1, s2, s3, i, j + 1, k + 1, m);
        }
        
        m[i][j] = ans ? 1 : 0;

        return ans;
    }
    
    vector<vector<vector<int>>> memo;
    
    bool isInterleave1(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        
        vector<vector<vector<int>>> m(s1.size(), vector<vector<int>>(s2.size(), vector<int>(s3.size())));
        this->memo = m;
        
        return dfs(s1, s2, s3, 0, 0, 0);
    }
    
    bool dfs(const string& s1, const string& s2, const string& s3, int i, int j, int k) {
        if (i >= s1.size()) {
            return s2.substr(j) == s3.substr(k);
        }
        
        if (j >= s2.size()) {
            return s1.substr(i) == s3.substr(k);
        }
        
        if (memo[i][j][k]) {
            return memo[i][j][k] == 1;
        }
        
        bool ans = false;
        
        if (s1[i] == s3[k]) {
            ans = ans || dfs(s1, s2, s3, i + 1, j, k + 1);
        }
        
        if (s2[j] == s3[k]) {
            ans = ans || dfs(s1, s2, s3, i, j + 1, k + 1);
        }
        
        memo[i][j][k] = ans ? 1 : 2;

        return ans;
    }
};


/*
babafasdassaxxv
bafadsax
basasxv
*/