package main
func minOperations(n int) int {
    if n % 2 == 0 {
        return  n * n / 4 // n / 2 * n / 2;
    }
    
    n /= 2
    
    return n * (n + 1)
}