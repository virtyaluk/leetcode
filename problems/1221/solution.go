package main
func balancedStringSplit(s string) int {
    r, l, count := 0, 0, 0
    
    for _, ch := range s {
        if ch == 'R' { r++ }
        if ch == 'L' { l++ }
        if r == l { count++ }
    }
    
    return count
}