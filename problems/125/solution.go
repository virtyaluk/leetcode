package main
func isPalindrome(s string) bool {
    if len(s) < 2 {
        return true
    }
    
    s = strings.ToLower(s)
    
    for l, h := 0, len(s) - 1; l < h; {
        if (s[l] < 'a' || s[l] > 'z') && (s[l] < '0' || s[l] > '9') {
            l++
            continue
        }
        
        if (s[h] < 'a' || s[h] > 'z') && (s[h] < '0' || s[h] > '9') {
            h--
            continue
        }
        
        if s[l] != s[h] {
            return false
        }
        
        l++
        h--
    }
    
    return true
}