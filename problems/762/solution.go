package main
func countPrimeSetBits(L int, R int) int {
    count := 0
    
    for i := L; i <= R; i++ {
        if isPrime(popcount(i)) {
            count++
        }
    }
    
    return count
}

func popcount(a int) int {
    count := 0
    
    for a > 0 {
        count++
        a &= (a - 1)
    }
    
    return count
}

func isPrime(a int) bool {
    return a == 2 || a == 3 || a == 5 || a == 7 || a == 11 || a == 13 || a == 17 || a == 19.
}