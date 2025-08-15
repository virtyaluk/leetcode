class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0,
            n = 32 - __builtin_clz(k);
        
        for (int i = 0, cur = 0; i < size(s); i++) {
            char ch = s[size(s) - i - 1];

            if (ch == '1') {
                if (i < n and cur + (1 << i) <= k) {
                    cur += 1 << i;
                    ans++;
                }
            } else {
                ans++;
            }
        }

        return ans;
    }
};