package main
const MOD int = 1000000007

func knightDialer(n int) int {
    ans, dp, g := 0, make([][]int, n + 1), [][]int{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}}
    
    for i, _ := range dp {
        dp[i] = make([]int, 10)
    }
    
    for i := 0; i < 10; i++ {
        ans = (ans + helper(n - 1, i, g, dp)) % MOD
    }
    
    return ans
}

func helper(n, b int, g, dp [][]int) int {
    if n == 0 {
        return 1
    }
    
    if dp[n][b] != 0 {
        return dp[n][b]
    }
    
    ans := 0
    
    for _, nb := range g[b] {
        ans = (ans + helper(n - 1, nb, g, dp)) % MOD
    }
    
    dp[n][b] = ans
    
    return dp[n][b]
}