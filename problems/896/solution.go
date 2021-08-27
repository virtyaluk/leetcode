package main
func isMonotonic(A []int) bool {
    a, b := true, true
    
    for i := 0; i < len(A) - 1; i++ {
        if !(A[i] <= A[i + 1]) {
            a = false
        }
        
        if !(A[i] >= A[i + 1]) {
            b = false
        }
    }
    
    return a || b
}