package main
func dominantIndex(nums []int) int {
    maxNum := 0
    
    for i, v := range nums {
        if v > nums[maxNum] {
            maxNum = i
        }
    }
    
    for i, v := range nums {
        if i != maxNum && nums[maxNum] < v * 2 {
            return -1
        }
    }
    
    return maxNum
}