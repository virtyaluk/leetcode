package main
func checkPossibility(nums []int) bool {
    p := -1
    
    for i := 0; i < len(nums) - 1; i++ {
        if nums[i] > nums[i + 1] {
            if p != -1 {
                return false
            }
            
            p = i
        }
    }
    
    return p == -1 || p == 0 || p == len(nums) - 2 || nums[p - 1] <= nums[p + 1] || nums[p] <= nums[p + 2]
}