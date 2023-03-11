class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = size(grid),
            n = size(grid.back());
        vector<vector<int>> diff(m, vector<int>(n));
        vector<int> colsOnes(n), rowsOnes(m);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowsOnes[i] += grid[i][j];
                colsOnes[j] += grid[i][j];
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diff[i][j] = rowsOnes[i] + colsOnes[j] - (n - rowsOnes[i]) - (m - colsOnes[j]);
            }
        }
        
        return diff;
    }
};