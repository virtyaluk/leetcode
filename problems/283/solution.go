package main
func moveZeroes(nums []int)  {
    j := 0
    
    for i := range nums {
        nums[j] = nums[i]
        
        if nums[i] != 0 {
            j++
        }
    }
    
    for ; j < len(nums); j++ {
        nums[j] = 0;
    }
}