package main
func numSmallerByFrequency(queries []string, words []string) []int {
    ans, w := make([]int, len(queries)), make([]int, len(words))
    
    for i, word := range words {
        w[i] = f(word)
    }
    
    for i, query := range queries {
        fr, count := f(query), 0
        
        for _, v := range w {
            if fr < v {
                count++
            }
        }
        
        ans[i] = count
    }
    
    return ans
}

func f(s string) int {
    minCh, count := 'z', 0
    
    for _, v := range s {
        if v < minCh {
            minCh, count = v, 1
        } else if minCh == v {
            count++
        }
    }
    
    return count
}