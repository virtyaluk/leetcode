package main
func addBoldTag(s string, dict []string) string {
    var ans strings.Builder
    bold := make([]bool, len(s) + 1)
    
    for i, end := 0, 0; i < len(s); i++ {
        for _, word := range dict {
            if strings.HasPrefix(s[i:], word) {
                end = max(end, i + len(word))
            }
        }
        
        bold[i] = end > i
    }
    
    for i := 0; i < len(s); i++ {
        if !bold[i] {
            ans.WriteRune(rune(s[i]))
            continue
        }
        
        j := i
        
        for j < len(s) && bold[j] {
            j++
        }
        
        ans.WriteString("<b>" + s[i:j] + "</b>")
        i = j - 1
    }
    
    return ans.String()
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}