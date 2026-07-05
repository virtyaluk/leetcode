class Solution {
public:
    int minFlips(string s) {
        int n = size(s),
            startWithOne = 0,
            startWithZero = 0,
            i = 0,
            ans = INT_MAX;
        string str = s + s;

        for (int j = 0; j < size(str); j++) {
            if (j % 2 == 0) {
                startWithOne += str[j] != '1';
                startWithZero += str[j] != '0';
            } else {
                startWithOne += str[j] != '0';
                startWithZero += str[j] != '1';
            }

            if (j - i + 1 > n) {
                if (i % 2 == 0) {
                    startWithOne -= str[i] != '1';
                    startWithZero -= str[i] != '0';
                } else {
                    startWithOne -= str[i] != '0';
                    startWithZero -= str[i] != '1';
                }

                i++;
            }

            if (j - i + 1 == n) {
                ans = min(ans, min(startWithOne, startWithZero));
            }
        }

        return ans;
    }
};