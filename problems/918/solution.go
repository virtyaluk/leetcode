package main
const MaxInt = int(^uint(0) >> 1)
const MinInt = -MaxInt - 1

func maxSubarraySumCircular(A []int) int {
    totalSum, maxSum, minSum, curMin, curMax := 0, MinInt, MaxInt, 0, 0
    
    for _, v := range A {
        totalSum += v
        curMax = max(v, curMax + v)
        maxSum = max(maxSum, curMax)
        curMin = min(v, curMin + v)
        minSum = min(minSum, curMin)
    }
    
    if maxSum > 0 {
        return max(maxSum, totalSum - minSum)
    }
    
    return maxSum
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}