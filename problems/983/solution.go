package main
const MaxInt = int(^uint(0) >> 1)
const MinInt = -MaxInt - 1

func mincostTickets(days []int, costs []int) int {
    n := days[len(days) - 1]
    dp := make([]int, n + 1)
    
    for _, day := range days {
        dp[day] = MaxInt
    }
    
    for i := 1; i < len(dp); i++ {
        if dp[i] == 0 {
            dp[i] = dp[i - 1]
        } else {
            dp[i] = min(dp[i], min(dp[i - 1] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2])))
        }
    }
    
    return dp[n]
}

func max(a, b int) int {
    if a > b { return a }
    return b
}

func min(a, b int) int {
    if a < b { return a }
    return b
}