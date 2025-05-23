class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;

        for (int i = 1, cnt = 1; i < size(s); i++) {
            if (s[i] == s[i - 1] + 1) {
                cnt++;
            } else {
                cnt = 1;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};