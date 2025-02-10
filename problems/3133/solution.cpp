class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x,
            mask = 1;
        n--;
        
        for (; n > 0; mask <<= 1) {
            if ((mask & x) == 0) {
                ans |= (n & 1) * mask;
                n >>= 1;
            }
        }
        
        return ans;
    }
};