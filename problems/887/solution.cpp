class Solution {
public:
    int superEggDrop(int k, int n) {
        int lo = 1, hi = n;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(k, n, mid) < n) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
    }
    
    int check(int k, int n, int x) {
        int ans = 0, r = 1;
        
        for (int i = 1; i <= k; i++) {
            r *= x - i + 1;
            r /= i;
            ans += r;
            
            if (ans >= n) {
                break;
            }
        }
        
        return ans;
    }
};