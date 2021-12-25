package main
func countLetters(S string) int {
    if len(S) == 0 {
        return 0
    }
    
    ans, count := 1, 1
    
    for i := 0; i < len(S) - 1; i++ {
        if S[i] == S[i + 1] {
            count++
            ans += count
        } else {
            count = 1
            ans += count
        }
    }
    
    return ans
}