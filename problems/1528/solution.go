package main
func restoreString(s string, indices []int) string {
    ans := make([]string, len(s))
    
    for i, pos := range indices {
        ans[pos] = string(s[i])
    }
    
    return strings.Join(ans, "")
}