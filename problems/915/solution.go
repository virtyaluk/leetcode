package main
func partitionDisjoint(nums []int) int {
    ans, runningMax, curMax := 1, nums[0], nums[0]
    
    for i, num := range nums {
        runningMax = max(runningMax, num)
        
        if num < curMax {
            ans = i + 1
            curMax = runningMax
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