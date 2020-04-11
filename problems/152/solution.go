package main
func maxProduct(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    
    ans := nums[0]
    
    for i := 0; i < len(nums); i++ {
        cur := 1
        
        for j := i; j < len(nums); j++ {
            cur *= nums[j]
            
            if cur > ans {
                ans = cur
            }
        }
    }
    
    return ans
}