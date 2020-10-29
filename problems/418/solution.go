package main
func wordsTyping(sentence []string, rows int, cols int) int {
    ans, curRow, curWord, spaces := 0, 0, 0, cols
    
    for curRow < rows {
        if len(sentence[curWord]) <= spaces {
            spaces -= len(sentence[curWord])
            spaces--
            curWord++
        } else {
            curRow++
            spaces = cols
        }
        
        if curWord >= len(sentence) {
            curWord = 0
            ans++
        }
    }
    
    return ans
}