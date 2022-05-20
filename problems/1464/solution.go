package main
import "sort"

func maxProduct(nums []int) int {
    sort.Ints(nums)
    
    n := len(nums) - 1
    
    return (nums[n] - 1) * (nums[n - 1] - 1)
}