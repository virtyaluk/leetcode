package main
func missingNumber(nums []int) int {
    n := len(nums)
    ans := n * (n + 1) / 2
    
    for _, num := range nums {
        ans -= num
    }
    
    return ans
}