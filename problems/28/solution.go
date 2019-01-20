func strStr(haystack string, needle string) int {
    if len(needle) == 0 {
        return 0
    }
    
    hl, nl := len(haystack), len(needle)
    
    for i := 0; i < hl - nl + 1; i++ {
        if needle[0] == haystack[i] && needle == haystack[i:i + nl] {
            return i
        }
    }
    
    return -1
}