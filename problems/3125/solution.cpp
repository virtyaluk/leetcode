class Solution {
public:
    long long maxNumber(long long n) {
        int x = 63 - __builtin_clzll(n);
        
        return (1ll << x) - 1;
    }
};