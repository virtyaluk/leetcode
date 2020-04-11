package main
func majorityElement(nums []int) int {
    m, mx, mv := map[int]int{}, 0, 0
    
    for _, v := range nums {
        m[v]++
        
        if m[v] >= mx {
            mx = m[v]
            mv = v
        }
    }
    
    return mv
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}