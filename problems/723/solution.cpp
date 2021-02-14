class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = size(board), n = size(board.front());
        bool rerun = false;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                int candy = abs(board[i][j]);
                
                if (candy and candy == abs(board[i][j + 1]) and candy == abs(board[i][j + 2])) {
                    board[i][j] = board[i][j + 1] = board[i][j + 2] = -candy;
                    rerun = true;
                }
            }
        }
        
        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j < n; j++) {
                int candy = abs(board[i][j]);
                
                if (candy and candy == abs(board[i + 1][j]) and candy == abs(board[i + 2][j])) {
                    board[i][j] = board[i + 1][j] = board[i + 2][j] = -candy;
                    rerun = true;
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            int k = m - 1;
            
            for (int i = m - 1; i >= 0; i--) {
                if (board[i][j] > 0) {
                    board[k--][j] = board[i][j];
                }
            }
            
            while (k >= 0) {
                board[k--][j] = 0;
            }
        }
        
        return rerun ? candyCrush(board) : board;
    }
};