package main
func sumZero(n int) []int {
    ans := []int{}
    
    for i := 1; i < n / 2 + 1; i++ {
        ans = append(ans, i, -i)
    }
    
    if n % 2 == 1 {
        ans = append(ans, 0)
    }
    
    return ans
}