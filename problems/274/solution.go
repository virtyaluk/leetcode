package main
func hIndex(citations []int) int {
    n, count := len(citations), 0
    b := make([]int, n + 1)
    
    for _, c := range citations {
        if c >= n {
            b[n]++
        } else {
            b[c]++
        }
    }
    
    for i := n; i >= 0; i-- {
        count += b[i]
        
        if count >= i {
            return i
        }
    }
    
    return 0
}