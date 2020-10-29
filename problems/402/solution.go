package main
func removeKdigits(num string, k int) string {
    for i := 0; i < len(num) - 1 && k > 0; i++ {
        if i >= 0 && num[i] > num[i + 1] {
            num = num[:i] + num[i + 1:]
            i -= 2
            k--
        }
    }
    
    for len(num) > 0 && num[0] == '0' {
        num = num[1:]
    }
    
    if len(num) - k >= 1 {
        return num[0:len(num) - k]
    }
    
    return "0"
}