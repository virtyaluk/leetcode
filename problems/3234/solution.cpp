class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = size(s),
            ans = 0;
        vector<int> dp(n + 1);
        dp[0] = -1;

        for (int i = 0; i < n; i++) {
            if (i == 0 or (i > 0 and s[i - 1] == '0')) {
                dp[i + 1] = i;
            } else {
                dp[i + 1] = dp[i];
            }
        }

        for (int i = 1; i <= n; i++) {
            int cnt0 = s[i - 1] == '0',
                j = i;
            
            while (j > 0 and cnt0 * cnt0 <= n) {
                int cnt1 = (i - dp[j]) - cnt0;

                if (cnt0 * cnt0 <= cnt1) {
                    ans += min(j - dp[j], cnt1 - cnt0 * cnt0 + 1);
                }

                j = dp[j];
                cnt0++;
            }
        }

        return ans;
    }
};