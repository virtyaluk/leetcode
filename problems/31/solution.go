func nextPermutation(nums []int)  {
    hi := len(nums) - 2
    
    for hi >= 0 && nums[hi] >= nums[hi + 1] {
        hi--
    }
    
    if hi >= 0 {
        lo := len(nums) - 1
        
        for nums[hi] >= nums[lo] {
            lo--
        }
        
        nums[hi], nums[lo] = nums[lo], nums[hi]
    }
    
    reverse(nums, hi + 1)
}

func reverse(nums []int, lo int) {
    hi := len(nums) - 1
    
    for lo <= hi {
        nums[lo], nums[hi] = nums[hi], nums[lo]
        lo++
        hi--
    }
}