func divide(dividend int, divisor int) int {
    neg, ans := 0, 0
    
    if dividend == -2147483648 && divisor == -1 {
        return abs(dividend) - 1
    }
    
    if (dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0) {
        neg = 1
    } else {
        neg = -1
    }
    
    dividend, divisor = abs(dividend), abs(divisor)
    
    if divisor == 1 {
        ans = dividend
    } else {
        for dividend >= divisor {
            dividend -= divisor
            ans++
        }
    }
    
    return ans * neg
}

func abs(a int) int {
    if a < 0 {
        return a * -1
    }
    
    return a
}