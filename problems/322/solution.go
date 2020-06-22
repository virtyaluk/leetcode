package main
const INT_MAX = (1 << 31) - 1

func coinChange(coins []int, amount int) int {
    dp := make([]int, amount + 1)
    
    for i := range dp {
        dp[i] = INT_MAX
    }
    
    dp[0] = 0
    
    for i := 1; i <= amount; i++ {
        for _, coin := range coins {
            if i >= coin {
                dp[i] = min(dp[i], 1 + dp[i - coin])
            }
        }
    }
    
    if dp[amount] == INT_MAX {
        return -1
    }
    
    return dp[amount]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}