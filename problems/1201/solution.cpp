class Solution {
private:
    long long int lcm(long long int a, long long int b) {
        return a * b / __gcd(a, b);
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long int lo = 1, hi = 2 * 1e9, ans = 0, _a = a, _b = b, _c = c, _n = n;
        
        while (lo <= hi) {
            long long int mid = lo + (hi - lo) / 2,
                cnt = 0;
            cnt += mid / _a;
            cnt += mid / _b;
            cnt += mid / _c;
            
            cnt -= mid / lcm(_a, _b);
            cnt -= mid / lcm(_b, _c);
            cnt -= mid / lcm(_c, _a);
            cnt += mid / lcm(_a, lcm(_b, _c));
            
            if (cnt >= _n) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};