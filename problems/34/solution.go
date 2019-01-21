func searchRange(nums []int, target int) []int {
    lo, hi := -1, -1
    
    for i := 0; i < len(nums); i++ {
        if (nums[i] == target && i == 0) || (nums[i] == target && nums[i - 1] != target) {
            lo = i
        }
        
        if (nums[i] == target && i == len(nums) - 1) || (nums[i] == target && nums[i + 1] != target) {
            hi = i
        }
    }
    
    return []int{lo, hi}
}