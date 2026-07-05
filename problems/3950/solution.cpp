class Solution {
public:
    bool consecutiveSetBits(int n) {
        bitset<64> bs(n);
        int ans = 0;

        for (int i = 0, curLen = 0; i < 64; i++) {
            if (not bs[i]) {
                curLen = 0;
            } else {
                curLen++;
            }

            ans += curLen >= 2;
        }

        return ans == 1;
    }
};