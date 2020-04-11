package main
func wordBreak(s string, wordDict []string) []string {
    ans := []string{}
    chSet := make([]bool, 26)
    
    for _, ch := range strings.Join(wordDict, "") {
        chSet[ch - 'a'] = true
    }
    
    for _, ch := range s {
        if !chSet[ch - 'a'] {
            return ans
        }
    }
    
    dfs(wordDict, s, "", 0, &ans)
    
    return ans
}

func dfs(words []string, str, curStr string, pos int, ans *[]string) {
    if pos >= len(str) {
        *ans = append(*ans, curStr[1:])
        return
    }
    
    for _, word := range words {
        wl := len(word)
        
        if pos+wl <= len(str) && str[pos:pos+wl] == word {
            dfs(words, str, curStr + " " + word, pos + wl, ans)
        }
    }
}