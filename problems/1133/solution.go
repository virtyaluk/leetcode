package main
func largestUniqueNumber(A []int) int {
    if len(A) == 1 {
        return A[0]
    }
    
    sort.Ints(A)
    
    for i := len(A) - 1; i >= 0; i-- {
        if (i == len(A) - 1 || A[i] != A[i+1]) && (i == 0 || A[i] != A[i-1]) {
            return A[i]
        }
    }
    
    return -1
}