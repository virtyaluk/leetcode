package main
const MaxInt = int(^uint(0) >> 1)

func minOperations(nums []int, x int) int {
    ans, sum, n := MaxInt, 0, len(nums)
    
    for _, num := range nums {
        sum += num
    }
    
    for left, right := 0, 0; right < n; right++ {
        sum -= nums[right]
        
        for left <= right && sum < x {
            sum += nums[left]
            left++
        }
        
        if (sum == x) {
            ans = min(ans, n - (right - left) - 1)
        }
    }
    
    if (ans == MaxInt) {
        return -1
    }
    
    return ans
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}