package main
import "fmt"

func shuffle(nums []int, n int) []int {
    ans, xi, yi := make([]int, n * 2), 0, n
    
    for i, _ := range ans {
        if i % 2 == 0 {
            ans[i] = nums[xi]
            xi++
        } else {
            ans[i] = nums[yi]
            yi++
        }
    }
    
    return ans
}