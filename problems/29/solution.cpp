class Solution {
public:
    int divide(int dividend, int divisor) {
        if (not dividend or not divisor) {
            return 0;
        }
        
        if (dividend == INT_MIN and divisor == -1) {
            return INT_MAX;
        }
        
        if (dividend == INT_MIN and divisor == 1) {
            return INT_MIN;
        }
        
        int neg = 2, ans = 0;
        
        if (dividend > 0) {
            neg--;
            dividend = -dividend;
        }
        
        if (divisor > 0) {
            neg--;
            divisor = -divisor;
        }
        
        vector<int> powersOfTwo, doubles;
        int powerOfTwo = -1, HALF_INT_MIN = INT_MIN / 2;
        
        while (dividend <= divisor) {
            doubles.push_back(divisor);
            powersOfTwo.push_back(powerOfTwo);
            
            if (divisor < HALF_INT_MIN) {
                break;
            }
            
            divisor += divisor;
            powerOfTwo += powerOfTwo;
        }
        
        for (int i = size(doubles) - 1; i >= 0; i--) {
            if (doubles[i] >= dividend) {
                ans += powersOfTwo[i];
                dividend -= doubles[i];
            }
        }
        
                if (neg != 1) {
            ans = -ans;
        }
        
        return ans;
    }
};