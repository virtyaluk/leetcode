class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = size(mat), n = size(mat.back());
        function<int(int, int)> getPoint = [&](int x, int y) {
            if (x < 0 or x >= m or y < 0 or y >= n) {
                return -1;
            }
            
            return mat[x][y];
        };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = mat[i][j];
                
                if (cur > getPoint(i - 1, j) and cur > getPoint(i + 1, j) and cur > getPoint(i, j + 1) and cur > getPoint(i, j - 1)) {
                    return {i, j};
                }
            }
        }
        
        return {};
    }
};