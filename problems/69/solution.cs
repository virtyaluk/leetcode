public class Solution {
    public int MySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        
        long lo = 0;
        long mid = 0;
        long hi = x;
        
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if (mid * mid == x) {
                return (int) mid;
            } else if (mid * mid < x) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return (int) hi;
    }
}