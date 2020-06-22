package main
func integerBreak(n int) int {
    if n == 2 {
        return 1
    }
    
    dp := make([]int, n + 1)
    dp[2] = 1
    
    for i := 3; i <= n; i++ {
        for j := 1; j < i; j++ {
            dp[i] = max(dp[i], j * (i - j), j * dp[i - j])
        }
    }
    
    return dp[n]
}

func max(vals... int) int {
    ans := vals[0]
    
    for _, val := range vals {
        if val > ans {
            ans = val
        }
    }
    
    return ans
}