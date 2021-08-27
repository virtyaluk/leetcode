package main
func transpose(A [][]int) [][]int {
    r, c  := len(A), len(A[0])
    transposed := make([][]int, c)
    
    for i := 0; i < c; i++ {
        transposed[i] = make([]int, r)
        
        for j := 0; j < r; j++ {
            transposed[i][j] = A[j][i]
        }
    }
    
    return transposed
}