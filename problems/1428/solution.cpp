/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int rows = binaryMatrix.dimensions()[0] - 1,
            cols = binaryMatrix.dimensions()[1] - 1,
            row = 0,
            col = cols;
        
        while (row <= rows and col >= 0) {
            if (binaryMatrix.get(row, col) == 1) {
                col--;
            } else {
                row++;
            }
        }
        
        if (col >= cols) {
            return -1;
        }
        
        return col + 1;
    }
};