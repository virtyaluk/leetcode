func search(nums []int, target int) int {
    lo, hi := 0, len(nums) - 1
    
    for lo <= hi {
        mid := lo + (hi - lo) / 2
        
        if nums[mid] == target {
            return mid
        } else if nums[mid] >= nums[lo] {
            if target >= nums[lo] && target <= nums[mid] {
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        } else {
            if target >= nums[mid] && target <= nums[hi] {
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
    }
    
    return -1
}