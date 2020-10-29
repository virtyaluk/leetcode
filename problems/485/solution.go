package main
func findMaxConsecutiveOnes(nums []int) int {
    curOnes, maxOnes := 0, 0
    
    for _, v := range nums {
        if v == 1 {
            curOnes++
        } else {
            curOnes = 0
        }
        
        maxOnes = max(maxOnes, curOnes)
    }
    
    return maxOnes
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}