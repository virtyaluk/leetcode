class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0,
            sum = 0;
        
        for (long long m = 1; n > 0;) {
            int d = n % 10;
            n /= 10;
        
            if (not d) {
                continue;
            }

            sum += d;
            x = d * m + x;
            m *= 10;
        }
        
        return x * sum;
    }
};