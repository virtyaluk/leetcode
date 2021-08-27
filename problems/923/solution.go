package main
const MOD int = 1000000007;

func threeSumMulti(arr []int, target int) int {
    dp := make([][]int, 3)
    
    for i := range dp {
        dp[i] = make([]int, target + 1)
    }
    
    for _, num := range arr {
        if num > target {
            continue
        }
        
        for i := target - num; i >= 0; i-- {
            dp[2][i + num] += dp[1][i]
            dp[2][i + num] %= MOD
            dp[1][i + num] += dp[0][i]
            dp[1][i + num] %= MOD
        }
        
        dp[0][num]++
    }
    
    return dp[2][target] % MOD
}


/*
arr = [1,1,2,2,3,3,4,4,5,5], target = 8
    1  2  3  4  5  6  7  8
0   2  2  2  2  2  0  0  0 
1   0  1  4  5  8  9  8  5 
2   0  0  0  2  4  10 14 20 

arr = [1,1,2,2,2,2], target = 5
    1  2  3  4  5
0   2  4  0  0  0 
1   0  1  8  6  0 
2   0  0  0  4  12 


*/