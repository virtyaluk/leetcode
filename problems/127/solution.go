package main
var az = [26]string{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}

func ladderLength(beginWord string, endWord string, wordList []string) int {
    ans, set, q := 1, map[string]bool{}, []string{beginWord}
    
    for _, word := range wordList {
        set[word] = true
    }
    
    for len(q) > 0 {
        nq := []string{}
        
        for _, word := range q {
            for i := 0; i < len(word); i++ {
                for _, ch := range az {
                    next := word[:i] + ch + word[i + 1:]
                    
                    if ok, _ := set[next]; ok {
                        if next == endWord {
                            return ans + 1
                        }
                        
                        nq = append(nq, next)
                        delete(set, next)
                    }
                }
            }
        }
        
        ans, q = ans + 1, nq
    }
    
    return 0
}