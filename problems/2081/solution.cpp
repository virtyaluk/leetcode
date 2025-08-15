class Solution {
private:
    int digit[100];

    bool isPalindrome(long long x, const int& k) {
        int len = -1;

        while (x) {
            len++;
            digit[len] = x % k;
            x /= k;
        }

        for (int i = 0, j = len; i < j; i++, j--) {
            if (digit[i] != digit[j]) {
                return false;
            }
        }

        return true;
    }
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        int lo = 1,
            cnt = 0;

        while (cnt < n) {
            int hi = lo * 10;

            for (int op = 0; op < 2; op++) {
                for (int i = lo; i < hi and cnt < n; i++) {
                    long long combined = i;
                    int x = (op == 0 ? i / 10 : i);

                    while (x) {
                        combined = combined * 10 + x % 10;
                        x /= 10;
                    }

                    if (isPalindrome(combined, k)) {
                        cnt++;
                        ans += combined;
                    }
                }
            }

            lo = hi;
        }

        return ans;
    }
};