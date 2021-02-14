package main
func isToeplitzMatrix(matrix [][]int) bool {
    for i := 0; i < len(matrix) - 1; i++ {
        for j := 0; j < len(matrix[0]) - 1; j++ {
            if matrix[i + 1][j + 1] != matrix[i][j] {
                return false
            }
        }
    }
    
    return true
}