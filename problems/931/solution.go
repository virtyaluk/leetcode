package main
const MaxInt = int(^uint(0) >> 1)

func minFallingPathSum(A [][]int) int {
    if len(A) == 0 {
        return 0
    }
    
    m, n := len(A), len(A[0])
    
    for i := 1; i < m; i++ {
        for j := 0; j < n; j++ {
            m, l, r := A[i - 1][j], MaxInt, MaxInt
            
            if j > 0 {
                l = A[i - 1][j - 1]
            }
            
            if j + 1 < n {
                r = A[i - 1][j + 1]
            }
            
            A[i][j] += min(l, m, r)
        }
    }
    
    return min(A[m - 1]...)
}

func min(nums ...int) int {
    m := nums[0]
    
    for _, num := range nums {
        if num < m {
            m = num
        }
    }
    
    return m
}