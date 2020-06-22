class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int nn = n;
        
        return nn != 0 && (nn & (nn - 1)) == 0;
    }
};