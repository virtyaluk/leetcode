package main
func findMaxLength(nums []int) int {
    m, count, ml := map[int]int{0:-1}, 0, 0
    // m[0] = -1
    
    for i := 0; i < len(nums); i++ {
        if nums[i] == 1 {
            count++
        } else {
            count--
        }
        
        if val, ok := m[count]; ok {
            ml = max(ml, i - val)
        } else {
            m[count] = i
        }
    }
    
    return ml
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}