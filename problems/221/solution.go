package main
func maximalSquare(matrix [][]byte) int {
    ans, m, n := 0, len(matrix), len(matrix[0])
    dp := make([]int, n + 1)
    
    for i := 1; i <= m; i++ {
        nextDp := make([]int, n + 1)

        for j := 1; j <= n; j++ {
            if matrix[i - 1][j - 1] == '1' {
                nextDp[j] = min(
                    nextDp[j - 1],
                    dp[j],
                    dp[j - 1],
                ) + 1
                
                ans = max(ans, nextDp[j])
            }
        }
        
        dp = nextDp
    }
    
    return ans * ans
}

func min(vals ...int) int {
    ans := vals[0]
    
    for _, val := range vals {
        if val < ans {
            ans = val
        }
    }
    
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}