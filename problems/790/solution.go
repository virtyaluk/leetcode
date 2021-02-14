package main
const MOD int = 1000000000 + 7

func numTilings(n int) int {
    memo := make([][]int, n + 1)
    
    for i := range memo {
        memo[i] = []int{-1, -1, -1, -1}
    }
    
    return dp(memo, 0, n, true, true)
}

func getState(t1, t2 bool) int {
    state := 0
    
    if t1 {
        state |= 1
    }
    
    if t2 {
        state |= 2
    }
    
    return state
}

func dp(memo [][]int, i, n int, t1, t2 bool) int {
    if i == n {
        return 1
    }
    
    ans, state, t3, t4 := 0, getState(t1, t2), i + 1 < n, i + 1 < n
    
    if memo[i][state] != -1 {
        return memo[i][state]
    }
    
    // |‾
    if t1 && t2 && t3 {
        ans += dp(memo, i + 1, n, false, true)
    }
    
    // |_
    if t1 && t2 && t4 {
        ans += dp(memo, i + 1, n, true, false)
    }
    
    // ‾|
    if t1 && !t2 && t3 && t4 {
        ans += dp(memo, i + 1, n, false, false)
    }
    
    // _|
    if !t1 && t2 && t3 && t4 {
        ans += dp(memo, i + 1, n, false, false)
    }
    
    // |
    if t1 && t2 {
        ans += dp(memo, i + 1, n, true, true)
    }
    
    // ‾
    if t1 && !t2 && t3 {
        ans += dp(memo, i + 1, n, false, true)
    }
    
    // _
    if !t1 && t2 && t4 {
        ans += dp(memo, i + 1, n, true, false)
    }
    
    // =
    if t1 && t2 && t3 && t4 {
        ans += dp(memo, i + 1, n, false, false)
    }
    
    // next col
    if !t1 && !t2 {
        ans += dp(memo, i + 1, n, true, true)
    }
    
    memo[i][state] = ans % MOD
    
    return memo[i][state]
}
