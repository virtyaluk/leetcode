package main
func arrayNesting(nums []int) int {
    m := 0
    
    for i, _ := range nums {
        j, c := nums[i], 1
        
        for nums[j] != nums[i] {
            c++
            j = nums[j]
        }
        
        m = max(m, c)
    }
    
    return m
}

func max(a, b int) int {
    if a > b { return a }
    return b
}