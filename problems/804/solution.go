package main
var morseCodes []string = []string{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}


func uniqueMorseRepresentations(words []string) int {
    transformations := make(map[string]int)

    for _, word := range words {
	    var sb strings.Builder
	
	    for _, char := range []byte(word) {
		    sb.WriteString(morseCodes[char - 97])	
	    }
	
	    transformations[sb.String()]++
    }

    return len(transformations)
}