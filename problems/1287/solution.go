package main
func findSpecialInteger(arr []int) int {
    for i := 0; i < 4; i++ {
        target := arr[len(arr) / 4 * i]
        
        lo, hi := 0, len(arr) - 1
        
        for lo < hi {
            mid := lo + (hi - lo) / 2
            
            if arr[mid] < target {
                lo = mid + 1
            } else {
                hi = mid
            }
        }
        
        if lo + len(arr) / 4 < len(arr) && target == arr[lo + len(arr) / 4] {
            return target
        }
    }
    
    return 0
}