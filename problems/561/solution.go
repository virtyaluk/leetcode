package main
import "sort"

func arrayPairSum(nums []int) int {
    sum := 0
    
    sort.Ints(nums)
    
    for i := 0; i < len(nums); i += 2 {
        sum += nums[i]
    }
    
    return sum
}