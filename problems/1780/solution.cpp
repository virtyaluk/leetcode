class Solution {
public:
    bool checkPowersOfThree(int n, int p = 1) {
        if (n == 0) {
            return true;
        }
        
        if (p > n) {
            return false;
        }
        
        return checkPowersOfThree(n, p * 3) or checkPowersOfThree(n - p, p * 3);
    }
};