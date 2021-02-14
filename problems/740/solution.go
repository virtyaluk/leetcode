package main
func deleteAndEarn(nums []int) int {
    skip, take, prev, count := 0, 0, -1, make([]int, 10001)
    
    for _, num := range nums {
        count[num]++
    }
    
    for i, c := range count {
        if c > 0 {
            m := max(take, skip)
            
            if prev != i - 1 {
                skip = m
                take = c * i + m
            } else {
                take = c * i + skip
                skip = m
            }
            
            prev = i
        }
    }
    
    return max(skip, take)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}