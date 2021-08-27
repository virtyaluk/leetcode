package main
func reverseOnlyLetters(S string) string {
    l, h := 0, utf8.RuneCountInString(S) - 1
    strAr := []rune(S)
    
    for l < h {
        for !unicode.IsLetter(strAr[l]) && l < h {
            l++
        }
        
        for !unicode.IsLetter(strAr[h]) && l < h {
            h--
        }
        
        strAr[l], strAr[h] = strAr[h], strAr[l]
        
        l++
        h--
    }
    
    return string(strAr)
}