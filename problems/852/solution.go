package main
func peakIndexInMountainArray(A []int) int {
    ans := 0
    
    for i := 1; i < len(A); i++ {
        if A[i] < A[i - 1] {
            ans = i - 1
            break
        }
    }
    
    return ans
}