class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1, col = 0;
        
        while (row >= 0 && col < matrix.back().size()) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                row--;
            } else {
                col++;
            }
        }
        
        return false;
    }
    
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        for (const vector<int>& row: matrix) {
            for (const int& col: row) {
                if (col == target) {
                    return true;
                }
            }
        }
        
        return false;
    }
};