/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int ans = INT_MAX,
            lo = 0,
            hi = mountainArr.length() - 1,
            n = hi,
            peak;
        
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        peak = lo;
        
        if (mountainArr.get(peak) == target) {
            return peak;
        }
        
        lo = 0;
        hi = peak;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2,
                val = mountainArr.get(mid);
            
            if (val == target) {
                ans = min(ans, mid);
                break;
            } else if (val < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        if (ans != INT_MAX) {
            return ans;
        }
        
        lo = peak + 1;
        hi = n;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2,
                val = mountainArr.get(mid);
            
            if (val == target) {
                ans = min(ans, mid);
                break;
            } else if (val > target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        if (ans != INT_MAX) {
            return ans;
        }
        
        return -1;
    }
};