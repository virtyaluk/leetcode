package main
func countSubstrings(s string) int {
    ans := 0
    
    for i := 0; i < len(s); i++ {
        ans += countPlaindromicSubstrings(s, i, i)
        ans += countPlaindromicSubstrings(s, i, i + 1)
    }
    
    return ans
}

func countPlaindromicSubstrings(s string, lo, hi int) int {
    ans := 0
    
    for lo >= 0 && hi < len(s) {
        if s[lo] != s[hi] {
            break
        }
        
        lo--
        hi++
        ans++
    }
    
    return ans
}