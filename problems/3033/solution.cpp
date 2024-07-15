class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = size(matrix),
            n = size(matrix.front());
        vector<int> cols(n, -1);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cols[j] = max(cols[j], matrix[i][j]);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = cols[j];
                }
            }
        }
        
        return matrix;
    }
};