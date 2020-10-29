package main
const MaxInt = int(^uint(0) >> 1)
const MinInt = -MaxInt - 1

func findUnsortedSubarray(nums []int) int {
    left, right, m, M := 0, len(nums) - 1, MaxInt, MinInt
    
    for i := 1; i < len(nums); i++ {
        if nums[i] < nums[i - 1] {
            m = min(m, nums[i])
        }
    }
    
    for i := len(nums) - 2; i >= 0; i-- {
        if nums[i] > nums[i + 1] {
            M = max(M, nums[i])
        }
    }
    
    for ; left < len(nums); left++ {
        if nums[left] > m {
            break
        }
    }
    
    for ; right >= 0; right-- {
        if nums[right] < M {
            break
        }
    }
    
    if left < right {
        return right - left + 1
    }
    
    return 0
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