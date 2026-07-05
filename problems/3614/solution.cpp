class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        for (const char& ch: s) {
            if (ch == '*') {
                if (len) {
                    len--;
                }
            } else if (ch == '#') {
                len *= 2;
            } else if (ch == '%') {
                continue;
            } else {
                len++;
            }
        }

        if (k + 1 > len) {
            return '.';
        }

        for (int i = size(s) - 1; i >= 0; i--) {
            if (s[i] == '*') {
                len++;
            } else if (s[i] == '#') {
                if (k + 1 > (len + 1) / 2) {
                    k -= len / 2;
                }

                len = (len + 1) / 2;
            } else if (s[i] == '%') {
                k = len - k - 1;
            } else {
                if (k + 1 == len) {
                    return s[i];
                } else {
                    len--;
                }
            }
        }

        return '.';
    }
};