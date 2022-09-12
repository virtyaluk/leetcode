package main
func numIdenticalPairs(nums []int) int {
    pairs := 0
    
    for i, _ := range nums {
        for j := i + 1; j < len(nums); j++ {
            if nums[i] == nums[j] {
                pairs++
            }
        }
    }
    
    return pairs
}