package main
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * type BinaryMatrix struct {
 *     Get(int, int) int
 *     Dimensions() []int
 * }
 */

func leftMostColumnWithOne(binaryMatrix BinaryMatrix) int {
    rows, cols := binaryMatrix.Dimensions()[0] - 1, binaryMatrix.Dimensions()[1] - 1
    row, col := 0, cols
    
    for row <= rows && col >= 0 {
        if binaryMatrix.Get(row, col) == 1 {
            col--
        } else {
            row++
        }
    }
    
    if col == cols {
        return -1
    }
    
    return col + 1
}