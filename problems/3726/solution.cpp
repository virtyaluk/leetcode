class Solution {
public:
    long long removeZeros(long long n) {
        long long ans = 0;

        for (const char ch: to_string(n)) {
            if (ch != '0') {
                ans = ans * 10 + (ch - '0');
            }
        }

        return ans;
    }
};