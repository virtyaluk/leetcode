class Solution {
public:
    int longestBalanced(string s) {
        int n = size(s),
            ans = 0;
        vector<int> cnt(26);

        for (int i = 0; i < n; i++) {
            fill(begin(cnt), end(cnt), 0);

            for (int j = i; j < n; j++) {
                bool flag = true;
                int c = s[j] - 'a';
                cnt[c]++;

                for (auto x: cnt) {
                    if (x > 0 and x != cnt[c]) {
                        flag = false;

                        break;
                    }
                }

                if (flag) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};