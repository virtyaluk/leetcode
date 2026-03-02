const int MOD = 1e9 + 7;

class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        int p = 0;

        while (p < size(s)) {
            if (s[p] == '0') {
                p++;
                continue;
            }

            int cnt = 0;

            while (p < size(s) and s[p] == '1') {
                cnt++;
                p++;
            }

            ans = ans + (1ll + (long long) cnt) * cnt / 2;
            ans = ans % MOD;
        }

        return ans;
    }
};