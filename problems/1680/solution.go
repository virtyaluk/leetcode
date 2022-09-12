package main
const MOD = 1000000007

func concatenatedBinary(n int) int {
    ans, size := 0, 0
    
    for i := 1; i <= n; i++ {
        if i & (i - 1) == 0 {
            size++
        }
        
        ans = ((ans << size) | i) % MOD
    }
    
    return ans
}