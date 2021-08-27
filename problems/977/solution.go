package main
func sortedSquares(A []int) []int {
    l, r, pos, ans := 0, len(A) - 1, len(A) - 1, make([]int, len(A))
    
    for l <= r {
        if A[l] * -1 > A[r] {
            ans[pos] = A[l] * A[l]
            l++
        } else {
            ans[pos] = A[r] * A[r]
            r--
        }
        
        pos--
    }
    
    return ans
}