class Solution {
public:
    int firstMatchingIndex(string s) {
        for (int i = 0, n = size(s); i <= n - i - 1; i++) {
            if (s[i] == s[n - i - 1]) {
                return i;
            }
        }

        return -1;
    }
};