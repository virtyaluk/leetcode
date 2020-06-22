package main
const MaxInt = int(^uint(0) >> 1)

func numSquares(n int) int {
    dp := make([]int, n + 1)
    
    for i, _ := range dp {
        dp[i] = MaxInt
    }
    
    dp[0] = 0
    
    for sq := 1; sq <= n; sq++ {
        for i := 1; i * i <= sq; i++ {
            dp[sq] = min(dp[sq], dp[sq - i*i] + 1)
        }
    }
    
    return dp[n]
}

func min(a, b int) int {
    if a < b { return a }
    return b
}