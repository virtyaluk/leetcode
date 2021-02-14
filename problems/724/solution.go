package main
func pivotIndex(nums []int) int {
    sum, leftSum := 0, 0
    
    for _, n := range nums {
        sum += n
    }
    
    for i := 0; i < len(nums); i++ {
        if leftSum == sum - leftSum - nums[i] {
            return i
        }
        
        leftSum += nums[i]
    }
    
    return -1
}