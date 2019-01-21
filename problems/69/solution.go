func mySqrt(x int) int {
    if x == 0 || x == 1 {
        return x
    }
    
    lo, hi, mid := 0, x, 0
    
    for lo <= hi {
        mid = lo + (hi - lo) / 2
        
        if mid * mid == x {
            return mid
        } else {
            if mid * mid < x {
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
    }
    
    return hi
}