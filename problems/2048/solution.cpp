class Solution {
private:
    bool isBalance(int x) {
        vector<int> freq(10);

        while (x > 0) {
            freq[x % 10]++;
            x /= 10;
        }

        for (int d = 0; d < 10; d++) {
            if (freq[d] > 0 and freq[d] != d) {
                return false;
            }
        }

        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++) {
            if (isBalance(i)) {
                return i;
            }
        }

        return -1;
    }
};