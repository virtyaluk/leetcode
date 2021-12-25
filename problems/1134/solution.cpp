class Solution {
public:
    bool isArmstrong(int n) {
        int numLen = log10(n) + 1,
            ans = 0,
            N = n;
        
        while (N) {
            ans += pow(N % 10, numLen);
            N /= 10;
        }
        
        return ans == n;
    }
};