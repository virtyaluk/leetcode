package main
func minimumTotal(triangle [][]int) int {
    dp := make([]int, len(triangle) + 1)
    
    for r := len(triangle) - 1; r >= 0; r-- {
        for c := 0; c < len(triangle[r]); c++ {
            dp[c] = triangle[r][c] + min(dp[c], dp[c + 1])
        }
    }
    
    return dp[0]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}