package main
import "strings"

func isPrefixOfWord(sentence string, searchWord string) int {
    if len(sentence) == 0 || len(searchWord) == 0 {
        return -1
    }
    
    for i, word := range strings.Split(sentence, " ") {
        if strings.HasPrefix(word, searchWord) {
            return i + 1
        }
    }
    
    return -1
}