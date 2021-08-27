package main
func prisonAfterNDays(cells []int, N int) []int {
    if N == 0 || N + 1 - 14 == 0 {
        return cells
    }
    
    cache := make([][]int, 14 + 1)
    cache[0] = cells
    
    for n := 1; n <= 14; n++ {
        cache[n] = make([]int, 8)
        
        for i:= 1; i < 8 - 1; i++ {
            cache[n][i] = btoi(cache[n - 1][i - 1] == cache[n - 1][i + 1])
        }
        
        if n == N {
            return cache[n]
        }
    }
    
    if N % 14 == 0 {
        return cache[14]
    }
    
    return cache[N % 14]
}

func btoi(c bool) int {
    if c {
        return 1
    }
    
    return 0
}