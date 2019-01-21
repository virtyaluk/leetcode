func maxSubArray(nums []int) int {
    bestSum, curSum := nums[0], nums[0]
    
    for _, v := range nums[1:] {
        curSum = max(v, curSum + v)
        bestSum = max(bestSum, curSum)
    }
    
    return bestSum
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}