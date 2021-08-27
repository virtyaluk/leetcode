package main
func findAndReplacePattern(words []string, pattern string) []string {
    ans, patSignature := []string{}, getStringSignature(pattern)
    
    for _, word := range words {
        if patSignature == getStringSignature(word) {
            ans = append(ans, word)
        }
    }
    
    return ans
}

func getStringSignature(str string) string {
    ans, freq := "", map[rune]int{}
    
    for _, ch := range str {
        if _, ok := freq[ch]; !ok {
            freq[ch] = len(freq) + 1
        }
        
        ans += string('a' + freq[ch])
    }
    
    return ans
}
