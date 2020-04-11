class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix.back());
        bool firstRow = false, firstCol = false;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    
                    if (not i) {
                        firstRow = true;
                    }
                    
                    if (not j) {
                        firstCol = true;
                    }
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 or matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (firstRow) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if (firstCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
    
    void setZeroes1(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix.back());
        vector<bool> vert(m), hor(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    vert[i] = true;
                    hor[j] = true;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = vert[i] or hor[j] ? 0 : matrix[i][j];
            }
        }
    }
};