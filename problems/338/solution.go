package main
func countBits(num int) []int {
    n := make([]int, num + 1)
    
    for i := 1; i <= num; i++ {
        if i % 2 == 0 {
            n[i] = n[i/2]
        } else {
            n[i] = n[i - 1] + 1
        }
    }
    
    return n
}