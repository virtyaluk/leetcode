class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int x = 0, y = 0, m = size(mat), n = size(mat.back());
        
        if (not m or m * n != r * c) {
            return mat;
        }
        
        vector<vector<int>> ans(r, vector<int>(c));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[x][y++] = mat[i][j];
                
                if (y >= c) {
                    y = 0;
                    x++;
                }
            }
        }
        
        return ans;
    }
};