const string special = "!@#$%^&*()-+";

class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        if (size(p) < 8) {
            return false;
        }

        int lower = 0,
            upper = 0,
            spec = 0,
            digits = 0;

        unordered_set<char> us(begin(special), end(special));

        for (int i = 0; i < size(p); i++) {
            if (i > 0 and p[i] == p[i - 1]) {
                return false;
            }

            lower += (p[i] >= 'a' and p[i] <= 'z');
            upper += (p[i] >= 'A' and p[i] <= 'Z');
            spec += us.count(p[i]);
            digits += isdigit(p[i]);
        }

        return lower and upper and spec and digits;
    }
};