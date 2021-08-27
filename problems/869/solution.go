package main
func reorderedPowerOf2(N int) bool {
    counter := getCounter(N)
    
    for i := 0; i < 32; i++ {
        if (1 << i == N || getCounter(1 << i) == counter) {
            return true
        }
    }
    
    return false
}

func getCounter(num int) int {
    ans := 0
    
    for ; num > 0; num /= 10 {
        ans += int(math.Pow(10.0, float64(num % 10)))
    }
    
    return ans
}