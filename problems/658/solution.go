package main
func findClosestElements(arr []int, k int, x int) []int {
    lo, hi, ans := 0, len(arr) - k, make([]int, k)
    
    for lo < hi {
        mid := lo + (hi - lo) / 2
        
        if x - arr[mid] > arr[mid + k] - x {
            lo = mid + 1
        } else {
            hi = mid
        }
    }
    
    for i := range ans {
        ans[i] = arr[lo + i]
    }
    
    return ans
}

func findClosestElements1(arr []int, k int, x int) []int {
    lo, hi, pos, ans := 0, len(arr) - 1, 0, make([]int, k)
    
    for lo <= hi {
        mid := lo + (hi - lo) / 2
        
        if arr[mid] <= x {
            lo = mid + 1
            pos = mid
        } else {
            hi = mid - 1
        }
    }
    
    lo = max(0, pos - k)
    hi = min(len(arr) - 1, pos + k)
    
    for hi - lo + 1 != k {
        if abs(x - arr[lo]) <= abs(x - arr[hi]) {
            hi--
        } else {
            lo++
        }
    }
    
    for i := range ans {
        ans[i] = arr[lo + i]
    }
    
    return ans
}

func abs(a int) int {
    if a > 0 {
        return a
    }
    
    return a * -1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}