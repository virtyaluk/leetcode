package main
func numJewelsInStones(J string, S string) int {
    m, ans := map[rune]int{}, 0
    
    for _, ch := range S {
        m[ch]++
    }
    
    for _, ch := range J {
        ans += m[ch]
    }
    
    return ans
}