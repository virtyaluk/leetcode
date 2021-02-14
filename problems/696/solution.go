package main
func countBinarySubstrings(s string) int {
    ans, prev, cur := 0, 0, 1
    
    for i := 1; i < len(s); i++ {
        if s[i] != s[i - 1] {
            ans += min(prev, cur)
            prev = cur
            cur = 1
        } else {
            cur++
        }
    }
    
    return ans + min(prev, cur)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}