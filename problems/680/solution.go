package main
func isPalindrome(s string, i, j int) bool {
    for i < j {
        if s[i] != s[j] {
            return false
        }
        i++
        j--
    }
    
    return true
}

func validPalindrome(s string) bool {
    for i, j := 0, len(s) - 1; i < j; {
        if (s[i] != s[j]) {
            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1)
        }
        
        i++
        j--
    }
    
    return true
}