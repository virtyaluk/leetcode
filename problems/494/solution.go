package main
func findTargetSumWays(nums []int, target int) int {
    dp := map[int]int{}
    
    dp[nums[0]]++
    dp[-nums[0]]++
    
    for i := 1; i < len(nums); i++ {
        newDp := map[int]int{}
        
        for sum, count := range dp {
            newDp[sum + nums[i]] += count
            newDp[sum - nums[i]] += count
        }
        
        dp = newDp
    }
    
    return dp[target]
}

func findTargetSumWays1(nums []int, target int) int {
    n := len(nums)
    dp := make([]map[int]int, n)
    
    for i := range dp {
        dp[i] = make(map[int]int)
    }
    
    dp[0][nums[0]]++
    dp[0][-nums[0]]++
    
    for i := 1; i < n; i++ {
        for sum, count := range dp[i - 1] {
            dp[i][sum + nums[i]] += count
            dp[i][sum - nums[i]] += count
        }
    }
    
    return dp[n - 1][target]
}