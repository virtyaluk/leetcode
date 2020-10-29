package main
func repeatedSubstringPattern(s string) bool {
    if len(s) <= 1 {
        return false
    }
    
    for size := 1; size <= len(s) / 2; size++ {
        window, start := s[0:size], size
        
        for start + size <= len(s) && window == s[start:start + size] {
            start = start + size
        }
        
        if start == len(s) {
            return true
        }
    }
    
    return false
}