func plusOne(digits []int) []int {
    hi, carry := len(digits) - 1, false
    digits[hi]++
    
    for hi >= 0 {
        if carry {
            digits[hi]++
            carry = false
        }
        
        if digits[hi] == 10 {
            digits[hi] = 0
            carry = true
        }
        
        hi--
    }
    
    if carry {
        return append([]int{1}, digits...)
    }
    
    return digits
}