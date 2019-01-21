class Solution:
    def mySqrt(self, x: int) -> int:
        if not x or x == 1:
            return x
        
        lo, hi, mid = 0, x, 0
        
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            
            if mid ** 2 == x:
                return mid
            elif mid ** 2 < x:
                lo = mid + 1
            else:
                hi = mid - 1
        
        return hi