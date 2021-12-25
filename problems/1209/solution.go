package main
func removeDuplicates(s string, k int) string {
    ra, i := []rune(s), 0
    
    for j := 0; j < len(ra); i, j = i + 1, j + 1 {
        ra[i] = ra[j]
        
        if (i >= k - 1 && check(ra, i, k)) {
            i -= k
        }
    }
    
    return string(ra[:i])
}

func check(ra []rune, i, k int) bool {
    for j := i - k + 1; j < i; j++ {
        if ra[i] != ra[j] {
            return false
        }
    }
    
    return true
}