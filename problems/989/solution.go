package main
func addToArrayForm(A []int, K int) []int {
    ar := []int{}
    i, cur := len(A) - 1, K
    
    for i >= 0 || cur > 0 {
        if i >= 0 {
            cur += A[i]
        }
        
        ar = append([]int{cur % 10}, ar...)
        cur /= 10
        i--
    }
    
    return ar
}