package main
func minSwaps(data []int) int {
    ans, ones, cur := 0, 0, 0
    
    for _, val := range data {
        ones += val
    }
    
    for i, val := range data {
        if i < ones {
            cur += val
            ans = ones - cur
        } else {
            cur += val
            cur -= data[i - ones]
            ans = min(ans, ones - cur)
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