package main
func uncommonFromSentences(A string, B string) []string {
    words := make(map[string]int)
	uniqueWords := []string{}
	
	for _, word := range strings.Split(A + " " + B, " ") {
		words[word]++
	}
	
	for word, count := range words {
		if count == 1 {
			uniqueWords = append(uniqueWords, word)
		}
	}
	
	return uniqueWords
}