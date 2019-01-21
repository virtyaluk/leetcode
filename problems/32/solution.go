func longestValidParentheses(s string) int {
    ans, left, right := 0, 0, 0
    
    for i := 0; i < len(s); i++ {
        if s[i] == '(' {
            left++
        } else {
            right++
        }
        
        if left == right {
            ans = max(ans, left + right)
        } else if right > left {
            left, right = 0, 0
        }
    }
    
    left, right = 0, 0
    
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == '(' {
            left++
        } else {
            right++
        }
        
        if left == right {
            ans = max(ans, left + right)
        } else if left > right {
            left, right = 0, 0
        }
    }
    
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}