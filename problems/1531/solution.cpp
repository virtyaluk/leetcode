class Solution {
private:
    int dp[101][101];
    
    int dfs(string& s, int lo, int K) {
        if (size(s) - lo <= K) {
            return 0;
        }
        
        if (dp[lo][K] == -1) {
            int ans = K ? dfs(s, lo + 1, K - 1) : 1000,
                k = K;
            
            for (int i = lo + 1, freq = 1; i <= size(s); i++) {
                ans = min(ans, dfs(s, i, k) + 1 + (freq >= 100 ? 3 : freq >= 10 ? 2 : freq > 1 ? 1 : 0));
                
                if (i == size(s)) {
                    break;
                }
                
                if (s[lo] == s[i]) {
                    freq++;
                } else if (--k < 0) {
                    break;
                }
            }
            
            dp[lo][K] = ans;
        }
        
        return dp[lo][K];
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        
        return dfs(s, 0, k);
    }
};