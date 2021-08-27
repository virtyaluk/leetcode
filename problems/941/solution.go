package main
func validMountainArray(A []int) bool {
    l, r := 0, len(A) - 1
    
    for l + 1 < len(A) && A[l] < A[l + 1] {
        l++
    }
    
    if l == 0 || l == len(A) - 1 {
        return false
    }
    
    for r - 1 >= 0 && A[r] < A[r - 1] {
        r--
    }
    
    return l == r
}