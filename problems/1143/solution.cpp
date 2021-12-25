#define ll long long int
typedef vector<ll> vll;
typedef vector<vll> vvll;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        ll n = text1.size(), m = text2.size();
        vvll dp(n + 1, vll(m + 1));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int dif = text1[i - 1] == text2[j - 1] ? 1 : 0;
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + dif});
            }
        }
        
        return dp[n][m];
    }
};