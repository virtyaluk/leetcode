package main
func hammingDistance(x int, y int) int {
    diff, xor := 0, x ^ y
    
    for i := 0; i < 32; i++ {
        if xor & (1 << i) != 0 {
            diff++
        }
    }
    
    return diff
}