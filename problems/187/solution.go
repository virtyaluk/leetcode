package main
func findRepeatedDnaSequences(s string) []string {
    hash, ans, sub := map[string]int{}, []string{}, ""
    
    for i := 0; i < len(s) - 10 + 1; i++ {
        sub = s[i:i+10]
        
        hash[sub]++
        
        if hash[sub] == 2 {
            ans = append(ans, sub)
        }
    }
    
    return ans
}