package main
func nthUglyNumber(n int) int {
    ugly, nmo2, nmo3, nmo5, i2, i3, i5 := make([]int, n), 2, 3, 5, 0, 0, 0
    ugly[0] = 1
    
    for i := 1; i < n; i++ {
        ugly[i] = min(nmo2, nmo3, nmo5)
        
        if ugly[i] == nmo2 {
            i2++
            nmo2 = ugly[i2] * 2
        }
        
        if ugly[i] == nmo3 {
            i3++
            nmo3 = ugly[i3] * 3
        }
        
        if ugly[i] == nmo5 {
            i5++
            nmo5 = ugly[i5] * 5
        }
    }
    
    return ugly[n - 1]
}

func min(ar ...int) int {
    m := ar[0]
    
    for _, num := range ar {
        if num < m {
            m = num
        }
    }
    
    return m
}