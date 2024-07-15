class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = size(s),
            ans = 0;
        vector<int> dp(26);
        
        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a',
                best = 0;
            
            for (int j = 0; j < 26; j++) {
                if (abs(j - cur) <= k) {
                    best = max(best, dp[j]);
                }
            }
            
            dp[cur] = max(dp[cur], best + 1);
            ans = max(ans, dp[cur]);
        }
        
        return ans;
    }
};