class NumMatrix {
public:
    vector<vector<int>> dp;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix.back());
        dp.resize(m + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
        // for (auto row: dp) {
        //     copy(begin(row), end(row), ostream_iterator<int>(cout, ", "));
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */