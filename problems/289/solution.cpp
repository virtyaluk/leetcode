class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> b(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = board[i][j];
            }
        }
        
        auto get = [&](int x, int y) {
            if (x < 0 || x >= m || y < 0 || y >= n) {
                return 0;
            }
            
            return b[x][y];
        };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int neighbors = 0;
                
                neighbors += get(i - 1, j);
                neighbors += get(i - 1, j - 1);
                neighbors += get(i, j - 1);
                neighbors += get(i + 1, j - 1);
                neighbors += get(i + 1, j);
                neighbors += get(i + 1, j + 1);
                neighbors += get(i, j + 1);
                neighbors += get(i - 1, j + 1);
                
                if (b[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    board[i][j] = 0;
                }
                
                if (b[i][j] == 0 && neighbors == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};