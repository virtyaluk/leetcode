class Solution {
public:
    long long maxRunTime(long long n, vector<int>& batteries) {
        long long lo = 1,
            hi = 0,
            mid = 0,
            sum = 0;
        
        for (const int& b: batteries) {
            sum += b;
        }
        
        hi = sum / n;
        
        while (lo < hi) {
            mid = hi - (hi - lo) / 2;
            long long run = 0;
        
            for (const int& b: batteries) {
                run += min((long long) b, mid);
            }
            
            if (run >= n * mid) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
    }
};