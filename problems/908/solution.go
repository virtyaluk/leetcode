package main
func smallestRangeI(A []int, K int) int {
    min, max := min(A...) + K, max(A...) - K
    
    if min > max {
        return 0
    }
    
    return max - min
}

func min(num ...int) int {
    m := num[0]
    
    for _, n := range num {
        if n < m {
            m = n
        }
    }
    
    return m
}

func max(num ...int) int {
    m := num[0]
    
    for _, n := range num {
        if n > m {
            m = n
        }
    }
    
    return m
}