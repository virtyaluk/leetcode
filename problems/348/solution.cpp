class TicTacToe {
public:
    vector<vector<int>> board;
    int n;
    
    /** Initialize your data structure here. */
    TicTacToe(int n): board{vector<vector<int>>(n, vector<int>(n))}{
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        
        bool horizontal = true, vertical = true, diagonal = true, antiDiagonal = true;
        
        for (int i = 0; i < n; i++) {
            if (board[row][i] != player) {
                horizontal = false;
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (board[i][col] != player) {
                vertical = false;
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (board[i][i] != player) {
                diagonal = false;
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (board[i][n - i - 1] != player) {
                antiDiagonal = false;
                break;
            }
        }
        
        if (horizontal or vertical or (row == col and diagonal) or (row == n - col - 1 and antiDiagonal)) {
            return player;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */