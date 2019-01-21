class Solution {
public:
    double myPow(double x, long n) {
        long N = n;
        
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1.0, curProduct = x;
        
        for (long i = N; i > 0; i /= 2) {
            if (i % 2 == 1) {
                ans *= curProduct;
            }
            
            curProduct *= curProduct;
        }
        
        return ans;
    }
    
    double myPow1(double x, long n) {
        if (not n) {
            return 1;
        }
        
        if (n < 0) {
            return myPow(1/x, -n);
        }
        
        double low = myPow(x, n / 2);
        
        if (n % 2 == 0) {
            return low * low;
        }
        
        return x * low * low;
    }
};