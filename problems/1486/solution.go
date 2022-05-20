package main
func xorOperation(n int, start int) int {
    ans := start
    
    for i := 1; i < n; i++ {
        ans ^= (start + 2*i)
    }
    
    return ans
}