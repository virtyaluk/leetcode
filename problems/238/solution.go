package main
func productExceptSelf(nums []int) []int {
    ans := make([]int, len(nums))
    
    for i := range ans {
        ans[i] = 1
    }
    
    for prev, i := 1, 0; i < len(nums); i++ {
        ans[i], prev = prev, prev * nums[i]
    }
    
    for prev, i := 1, len(nums) - 1; i >= 0; i-- {
        ans[i], prev = ans[i] * prev, prev * nums[i]
    }
    
    return ans
}