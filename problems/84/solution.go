package main
const MaxInt = int(^uint(0) >> 1)
const MinInt = -MaxInt - 1

func largestRectangleArea(heights []int) int {
    n, ans := len(heights), 0
    
    for i := 0; i < n; i++ {
        minHeight := MaxInt
        
        for j := i; j < n; j++ {
            minHeight = min(minHeight, heights[j])
            ans = max(ans, minHeight * (j - i + 1))
        }
    }
    
    return ans
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}

