class Solution {
public:
    bool isPowerOfThree(int n) {
        for (int i = 0; i <= 19; i++) {
            if (pow(3, i) == n) {
                return true;
            }
        }
        
        return false;
    }
    
    bool isPowerOfThree1(int n) {
        return fmod(log10((double) n) / log10((double) 3), 1) == 0;
    }
};