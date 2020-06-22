class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shifts = 0;
        
        while (m != n) {
            m >>= 1;
            n >>= 1;
            shifts++;
        }
        
        return m << shifts;
    }
};