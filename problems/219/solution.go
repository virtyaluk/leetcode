package main
func containsNearbyDuplicate(nums []int, k int) bool {
    for i := 0; i < len(nums); i++ {
        for j := max(0, i - k); j < i; j++ {
            if nums[i] == nums[j] {
                return true
            }
        }
    }
    
    return false;
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}