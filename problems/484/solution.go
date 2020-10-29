package main
func findPermutation(s string) []int {
    ans, i := make([]int, len(s) + 1), 1
    ans[0] = 1
    
    for i <= len(s) {
        ans[i] = i + 1
        j := i
        
        if s[i - 1] == 'D' {
            for i <= len(s) && s[i - 1] == 'D' {
                i++
            }
            
            for k, c := j - 1, i; k <= i - 1; k, c = k + 1, c - 1 {
                ans[k] = c
            }
        } else {
            i++
        }
    }
    
    return ans
}