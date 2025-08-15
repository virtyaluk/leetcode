const int MOD = 1e9 + 7;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int ans = 0;
        vector<int> freq(26);

        for (const char& ch: s) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            vector<int> next(26);
            next[0] = freq[25];
            next[1] = (freq[25] + freq[0]) % MOD;

            for (int i = 2; i < 26; i++) {
                next[i] = freq[i - 1];
            }

            freq = move(next);
        }

        for (int i = 0; i < 26; i++) {
            ans = (ans + freq[i]) % MOD;
        }

        return ans;
    }
};