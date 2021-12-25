package main
const MaxInt = int(^uint(0) >> 1)

func commonChars(A []string) []string {
    a, ans := make([]int, 26), []string{}
    
    for i, _ := range a {
        a[i] = MaxInt
    }
    
    for _, word := range A {
        b := make([]int, 26)

        for _, ch := range word {
            b[ch - 'a']++
        }
        
        for i, _ := range b {
            a[i] = min(a[i], b[i])
        }
    }
    
    for i, _ := range a {
        for a[i] > 0 {
            a[i]--
            ans = append(ans, string('a' + i))
        }
    }
    
    return ans
}

func min(a, b int) int {
    if a < b { return a }
    return b
}