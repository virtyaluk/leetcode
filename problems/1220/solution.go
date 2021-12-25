package main
func countVowelPermutation(n int) int {
    a, e, i, o, u, MOD := 1, 1, 1, 1, 1, 1000000000 + 7
    
    for j := 1; j < n; j++ {
        a, e, i, o, u = (e + i + u) % MOD, (a + i) % MOD, (e + o) % MOD, i % MOD, (i + o) % MOD
    }
    
    return (a + e + i + o + u) % MOD
}
