package main
func wordPattern(pattern string, str string) bool {
    words := strings.Split(str, " ")
    
    if len(pattern) != len(words) {
        return false
    }
    
    wordToCh, chToWord := make(map[string]byte), make(map[byte]string)
    
    for i := 0; i < len(words); i++ {
        word, ch := words[i], pattern[i]
        
        nextCh, ok1 := wordToCh[word]
        nextWord, ok2 := chToWord[ch]
        
        if !ok1 && !ok2 {
            wordToCh[word] = ch
            chToWord[ch] = word
        } else if nextCh != ch || nextWord != word {
            return false
        }
    }
    
    return true
}