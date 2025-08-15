class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0,
            p = 1,
            m = n;
        
        while (m) {
            s += m % 10;
            p *= m % 10;
            m /= 10;
        }

        return n % (s + p) == 0;
    }
};