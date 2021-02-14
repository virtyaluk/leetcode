class Solution {
private:
    long long zeta(long long x) {
        if (x > 0) {
            return x / 5 + zeta(x / 5);
        }
        
        return 0;
    }
public:
    int preimageSizeFZF(int k) {
        long long lo = k,
            hi = 10 * (long long) k + 1;
        
        while (lo < hi) {
            long long mid = (lo + hi) / 2,
                zmid = zeta(mid);
            
            if (zmid == k) {
                return 5;
            } else if (zmid < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return 0;
    }
};