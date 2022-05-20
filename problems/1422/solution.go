package main
func maxScore(s string) int {
    ans, ones, zeroes := 0, 0, 0
    
    for _, ch := range s {
        if ch == '1' {
            ones++
        }
    }
    
    if ones == 0 {
        return len(s) - 1
    }
    
    for i, _ := range s {
        if i == len(s) - 1 {
            continue
        }
        
        if s[i] == '1' {
            ones--
        } else {
            zeroes++
        }
        
        ans = max(ans, ones + zeroes)
    }
    
    return ans
}

func max(a, b int) int {
    if a > b { return a }
    return b
}