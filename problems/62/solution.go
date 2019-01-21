func uniquePaths(m int, n int) int {
    dp := make([][]int, m + 1)
    
    for i, _ := range dp {
        dp[i] = make([]int, n + 1)
    }
    
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if i == 1 && j == 1 {
                dp[i][j] = 1
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
            }
        }
    }
    
    return dp[m][n]
}