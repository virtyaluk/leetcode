package main
func fib(N int) int {
    if N == 0 {
        return 0
    }
    
    if N == 1 || N == 2 {
        return 1
    }
    
    dp := make([]int, N + 1)
    dp[0], dp[1], dp[2] = 0, 1, 1
    
    for i := 3; i <= N; i++ {
        dp[i] = dp[i - 1] + dp[i - 2]
    }
    
    return dp[N]
}