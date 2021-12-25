package main
func calculateTime(keyboard string, word string) int {
    m, i, ans := map[rune]int{}, 0, 0
    
    for i, ch := range keyboard {
        m[ch] = i
    }
    
    for _, ch := range word {
        j := m[ch]
        ans, i = ans + abs(i - j), j
        
    }
    
    return ans
}

func abs(a int) int {
    if a < 0 { return a * -1 }
    return a
}