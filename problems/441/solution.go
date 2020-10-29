package main
func arrangeCoins(n int) int {
    lo, hi := 0, n
    
    for lo <= hi {
        mid := lo + (hi - lo) / 2
        curr := mid * (mid + 1) / 2
        
        if curr == n {
            return mid
        } else if curr > n {
            hi = mid - 1
        } else {
            lo = mid + 1
        }
    }
    
    return hi
}