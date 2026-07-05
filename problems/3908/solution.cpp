class Solution {
public:
    bool validDigit(int n, int x) {
        string nstr = to_string(n);

        if (nstr.front() - '0' == x) {
            return false;
        }

        for (const char& ch: nstr) {
            if (ch - '0' == x) {
                return true;
            }
        }

        return false;
    }
};