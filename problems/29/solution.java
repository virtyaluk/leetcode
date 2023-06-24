class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        
        int neg = 2, ans = 0, HALF_INT_MIN = Integer.MIN_VALUE / 2;

        if (dividend > 0) {
            neg--;
            dividend = -dividend;
        }
        
        if (divisor > 0) {
            neg--;
            divisor = -divisor;
        }
        
        while (dividend <= divisor) {
            int powerOfTwo = -1, value = divisor;
            
            while (value >= HALF_INT_MIN && value + value >= dividend) {
                value += value;
                powerOfTwo += powerOfTwo;
            }
            
            ans += powerOfTwo;
            dividend -= value;
        }

        if (neg != 1) {
            return -ans;
        }
        
        return ans;
    }
}