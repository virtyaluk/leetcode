class Solution {
public:
    inline static const string base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string concatHex36(int n) {
        return toBase(n * n, 16) + toBase(n * n * n, 36);
    }

    string toBase(int i, int b = 36) {
        string ans;

        while (i) {
            ans = base[i % b] + ans;
            i /= b;
        }

        return ans;
    }
};