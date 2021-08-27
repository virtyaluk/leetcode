const int MOD = 1e9 + 7;

class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long int> dp(26, 0);
        
        for (const char& ch: s) {
            dp[ch - 'a'] = accumulate(begin(dp), end(dp), 1l) % MOD;
        }
        
        return accumulate(begin(dp), end(dp), 0l) % MOD;
    }
};


/*

abc

[0, 0, 0]
[1, 0, 0]
[1, 2, 0]
[1, 2, 4]

7

aba
[0, 0]
[1, 0]
[1, 2]
[4, 2]

6

aaa
[0]
[1]
[2]
[3]

*/