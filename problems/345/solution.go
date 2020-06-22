package main
func reverseVowels(s string) string {
    l, h, str := -1, len(s), []rune(s)
    
    for l < h {
        l++
        for (l < h && !isVowel(str[l])) {
            l++
        }
        
        h--
        for (l < h && !isVowel(str[h])) {
            h--
        }
        
        if l < h {
            str[l], str[h] = str[h], str[l]
        }
    }
    
    return string(str)
}

func isVowel(char rune) bool {
    switch char {
    case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I','O', 'U':
        return true
        
    default:
        return false
    }
}