package main
func countSquares(matrix [][]int) int {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return 0
    }
    
    ans, m, n := 0, len(matrix), len(matrix[0])
    dp := make([][]int, m + 1)
    
    for i := 0; i < len(dp); i++ {
        dp[i] = make([]int, n + 1)
    }
    
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if matrix[i - 1][j - 1] > 0 {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1
                ans += dp[i][j]
            }
        }
    }
    
    return ans
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}