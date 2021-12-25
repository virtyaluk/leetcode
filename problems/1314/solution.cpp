class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = size(mat), n = size(mat.back());
        vector<vector<int>> sum(m, vector<int>(n)), ans(m, vector<int>(n));
        function<int(int, int)> getSum = [&](int x, int y) {
            if (x < 0 or y < 0) {
                return 0;
            }
            
            if (x >= m) {
                x = m - 1;
            }
            
            if (y >= n) {
                y = n - 1;
            }
            
            return sum[x][y];
        };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] = mat[i][j] + getSum(i - 1, j) + getSum(i, j - 1) - getSum(i - 1, j - 1);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = getSum(i + k, j + k) + getSum(i - k - 1, j - k - 1) - getSum(i + k, j - k - 1) - getSum(i - k - 1, j + k);
            }
        }
        
        return ans;
    }
};