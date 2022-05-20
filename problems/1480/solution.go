package main
func runningSum(nums []int) []int {
    acc := 0
    
    for i, num := range nums {
        acc += num
        nums[i] = acc
    }
    
    return nums
}