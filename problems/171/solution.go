package main
func titleToNumber(s string) int {
    ans := 0
    
    for _, ch := range s {
        ans = (int(ch) - 'A' + 1) + 26 * ans
    }
    
    return ans
}