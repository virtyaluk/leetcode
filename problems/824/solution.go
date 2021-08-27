package main
func toGoatLatin(S string) string {
    vowels := []rune{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' }
    words := []string{}
    
    for i, word := range strings.Split(S, " ") {
        if !contains(vowels, rune(word[0])) {
            word = string(word[1:]) + string(word[0])
        }
        
        words = append(words, word + "ma" + strings.Repeat("a", i + 1))
    }
    
    return strings.Join(words, " ")
}

func contains(list []rune, el rune) bool {
    for _, v := range list {
        if v == el {
            return true
        }
    }
    
    return false;
}