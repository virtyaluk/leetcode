package main
func replaceWords(dictionary []string, sentence string) string {
    sort.Slice(dictionary, func(i, j int) bool {
        return dictionary[i] < dictionary[j]
    })
    
    words := strings.Split(sentence, " ")
    
    for i, word := range words {
        for _, dict := range dictionary {
            if strings.HasPrefix(word, dict) {
                words[i] = dict
                break
            }
        }
    }
    
    return strings.Join(words, " ")
}