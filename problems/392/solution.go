package main
func isSubsequence(s string, t string) bool {
    // if len(s) > len(t) {
    //     return false
    // }
    
    // if len(s) == 0 {
    //     return true
    // }
    
    p := 0
    
    for _, ch := range t {
        if p == len(s) {
            return true
        }
        
        if ch == rune(s[p]) {
            p++
        }
    }
    
    return p == len(s)
}