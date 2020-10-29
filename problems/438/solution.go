package main
import "fmt"

func findAnagrams(s string, p string) []int {
    chCount, ans := make([]int, 26), []int{}
    
    for _, ch := range p {
        chCount[ch - 'a']++
    }
    
    left, right, count := 0, 0, len(p)
    
    for right < len(s) {
        if chCount[s[right] - 'a'] >= 1 {
            count--
        }
        
        chCount[s[right] - 'a']--
        right++
        
        if count == 0 {
            ans = append(ans, left)
        }
        
        if right - left == len(p) {
            if chCount[s[left] - 'a'] >= 0 {
                count++
            }
            
            chCount[s[left]  - 'a']++
            left++
        }
    }
    
    return ans
}