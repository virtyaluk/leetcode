package main
const MaxInt = int(^uint(0) >> 1)
const MinInt = -MaxInt - 1

func maxSumDivThree(nums []int) int {
    n := len(nums)
    dp := make([][]int, n + 1)
    
    for i := range dp {
        dp[i] = make([]int, 3)
    }
    
    dp[0][1] = MinInt
    dp[0][2] = MinInt
    
    for i := 1; i <= n; i++ {
        num := nums[i - 1]
        
        if num % 3 == 0 {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + num)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] + num)
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][2] + num)
        } else if num % 3 == 1 {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + num)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + num)
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + num)
        } else {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] + num)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + num)
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + num)
        }
    }
    
    return dp[n][0]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}