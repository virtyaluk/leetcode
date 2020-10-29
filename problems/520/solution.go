package main
func detectCapitalUse(word string) bool {
    allCaps, allLows, capital := word[0] <= 'Z',  word[0] >= 'a', word[0] <= 'Z'
    
    for i := 1; i < len(word); i++ {
        ch := word[i]
        allCaps = allCaps && ch <= 'Z'
        allLows = allLows && ch >= 'a'
        capital = capital && ch >= 'a'
    }
    
    return allCaps || allLows || capital
}