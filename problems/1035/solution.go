package main
func maxUncrossedLines(A []int, B []int) int {
    m, n := len(A), len(B)
    dp := make([][]int, m + 1)
    
    for i := 0; i < len(dp); i++ {
        dp[i] = make([]int, n + 1)
    }
    
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if A[i - 1] == B[j - 1] {
                dp[i][j] = dp[i - 1][j - 1] + 1
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
            }
        }
    }
    
    return dp[m][n]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}