package main
func findNumbers(nums []int) int {
    ans := 0
    
    for _, n := range nums {
        if int(math.Floor(math.Log10(float64(n))) + 1.0) % 2 == 0 {
            ans++
        }
    }
    
    return ans
}