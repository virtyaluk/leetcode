package main
import "strconv"

func addStrings(num1 string, num2 string) string {
    n1l, n2l, ans, cur := len(num1) - 1, len(num2) - 1, "", false
    
    for n1l > -1 || n2l > -1 {
        ns := 0
        
        if n1l > -1 {
            ns += int(num1[n1l] - '0')
            n1l--
        }
        
        if n2l > -1 {
            ns += int(num2[n2l] - '0')
            n2l--
        }
        
        if cur {
            ns++
            cur = false
        }
        
        if ns > 9 {
            cur = true
            ns -= 10
        }
        
        ans = strconv.Itoa(ns) + ans
    }
    
    if cur {
        ans = "1" + ans
    }
    
    return ans
}