package main
func suggestedProducts(products []string, searchWord string) [][]string {
    ans := make([][]string, len(searchWord))
    
    sort.Strings(products)
    
    for i := 0; i < len(searchWord); i++ {
        input := searchWord[:i + 1]
        
        for _, word := range products {
            if strings.HasPrefix(word, input) {
                ans[i] = append(ans[i], word)
            }
            
            if len(ans[i]) == 3 {
                break
            }
        }
    }
    
    return ans
}