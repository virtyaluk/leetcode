class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 0, hi = m * n;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2,
                count = 0;
            
            for (int i = 1; i <= m; i++) {
                if (n < mid / i) {
                    count += n;
                } else {
                    count += mid / i;
                }
            }
            
            if (count >= k) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};