package main
func singleNonDuplicate(nums []int) int {
    lo, hi := 0, len(nums) / 2
    
    for lo < hi {
        mid := lo + (hi - lo) / 2
        
        if nums[mid * 2] != nums[mid * 2 + 1] {
            hi = mid
        } else {
            lo = mid + 1
        }
    }
    
    return nums[lo * 2]
}