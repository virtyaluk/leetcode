class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = size(s),
            i = 0;

        for (int j = 0; j < n; j++) {
            if (s[j] == s[i]) {
                continue;
            }

            if (j - i == k) {
                return true;
            }

            i = j;
        }

        return (n - i) == k;
    }
};