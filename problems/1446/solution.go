package main
func maxPower(s string) int {
    ans := 0
    
    for i := 0; i < len(s); i++ {
        j := 0
        
        for i + j < len(s) && s[i] == s[i + j] {
            j++
        }
        
        i += j - 1
        ans = max(ans, j)
    }
    
    return ans
}

func max(a, b int) int {
    if a > b { return a }
    return b
}