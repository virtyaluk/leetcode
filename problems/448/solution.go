package main
func findDisappearedNumbers(nums []int) []int {
    ans := []int{}
    
    if len(nums) == 0 {
        return ans
    }
    
    for i, _ := range nums {
        idx := abs(nums[i])
        nums[idx - 1] = abs(nums[idx - 1]) * -1
    }
    
    for i, _ := range nums {
        if nums[i] > 0 {
            ans = append(ans, i + 1)
        }
    }
    
    return ans
}

func abs(a int) int {
    if a < 0 { return a * -1 }
    return a
}