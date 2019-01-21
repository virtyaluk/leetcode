func trap(height []int) int {
    ans, lo, hi, leftMax, rightMax := 0, 0, len(height) - 1, 0, 0
    
    for lo < hi {
        if height[lo] < height[hi] {
            leftMax = max(leftMax, height[lo])
            ans += leftMax - height[lo]
            lo++
        } else {
            rightMax = max(rightMax, height[hi])
            ans += rightMax - height[hi]
            hi--
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