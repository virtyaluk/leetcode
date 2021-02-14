package main
func search(nums []int, target int) int {
    if len(nums) == 1 {
        if nums[0] == target {
            return 0
        } else {
            return -1
        }
    }
    
    lo, hi := 0, len(nums) - 1
    
    for lo <= hi {
        mid := lo + (hi - lo) / 2
        
        if nums[mid] == target {
            return mid
        } else if target > nums[mid] {
            lo = mid + 1
        } else {
            hi = mid - 1
        }
    }
    
    return -1
}