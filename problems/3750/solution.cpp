class Solution {
public:
    int minimumFlips(int n) {
        int ans = 0,
            tmp = n,
            lo = 0,
            hi = -1;
        
        while (tmp > 0) {
            tmp >>= 1;
            hi++;
        }

        while (lo < hi) {
            ans += ((n >> lo) & 1) ^ ((n >> hi) & 1);
            lo++;
            hi--;
        }

        return 2 * ans;
    }
};