package main
func numFactoredBinaryTrees(arr []int) int {
    ans, MOD, dp := 0, 1000000007, map[int]int{}
    
    sort.Ints(arr)
    
    for i := 0; i < len(arr); i++ {
        dp[arr[i]] = 1
        
        for j := 0; j < i; j++ {
            if arr[i] % arr[j] == 0 {
                dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % MOD
            }
        }
        
        ans = (ans + dp[arr[i]]) % MOD
    }
    
    return ans % MOD
}