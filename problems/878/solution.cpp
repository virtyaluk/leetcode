typedef long long int ll;

const int MOD = 1e9 + 7;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll lo = min(a, b), hi = (ll) n * lo, _lcm = lcm(a, b);
        
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            
            if (mid / a + mid / b - mid / _lcm < n) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return lo % MOD;
    }
};