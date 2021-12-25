package main
func longestStrChain(words []string) int {
    ans, dp := 1, map[string]int{}
    
    sort.Slice(words, func(i, j int) bool {
        return len(words[i]) < len(words[j])
    })
    
    for _, word := range words {
        curLen := 1
        
        for i := 0; i < len(word); i++ {
            prevWord := word[:i] + word[i + 1:]
            
            if val, ok := dp[prevWord]; ok {
                curLen = max(curLen, 1 + val)
            }
        }
        
        dp[word] = curLen
        ans = max(ans, curLen)
    }
    
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}