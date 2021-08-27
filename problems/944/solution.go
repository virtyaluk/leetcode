package main
func minDeletionSize(A []string) int {
    count := 0
        
    for c := 0; c < len(A[0]); c++ {
        for i := 0; i < len(A) - 1; i++ {
            if (A[i][c] > A[i + 1][c]) {
                count++
                break
            }
        }
    }

    return count
}