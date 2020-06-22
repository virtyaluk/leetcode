package main
func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
    // sort.Ints(nums)
    
    for i := 0; i < len(nums) - 1; i++ {
        for j := i + 1; j < len(nums); j++ {
            if abs(j - i) <= k && abs(nums[j] - nums[i]) <= t {
                return true
            }
        }
    }
    
    return false
}

func abs(num int) int {
    if num < 0 {
        return num * -1
    }
    
    return num
}