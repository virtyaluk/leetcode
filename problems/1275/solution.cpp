class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int player = 1;
        vector<vector<int>> board(3, vector<int>(3));
        
        for (const vector<int>& move: moves) {
            int row = move[0], col = move[1];
            board[row][col] = player;
            
            if (checkRow(board, row, player) or checkCol(board, col, player) or (row == col and checkDiagonal(board, player)) or (row + col == 3 - 1 and checkAntidiagonal(board, player))) {
                return player == 1 ? "A" : "B";
            }
            
            player *= -1;
        }
        
        if (size(moves) == 9) {
            return "Draw";
        }
        
        return "Pending";
    }
    
    bool checkRow(const vector<vector<int>>& b, int row, int player) {
        for (int i = 0; i < 3; i++) {
            if (b[row][i] != player) {
                return false;
            }
        }
        
        return true;
    }
    
    bool checkCol(const vector<vector<int>>& b, int col, int player) {
        for (int i = 0; i < 3; i++) {
            if (b[i][col] != player) {
                return false;
            }
        }
        
        return true;
    }
    
    bool checkDiagonal(const vector<vector<int>>& b, int player) {
        for (int i = 0; i < 3; i++) {
            if (b[i][i] != player) {
                return false;
            }
        }
        
        return true;
    }
    
    bool checkAntidiagonal(const vector<vector<int>>& b, int player) {
        for (int i = 0; i < 3; i++) {
            if (b[i][2 - i] != player) {
                return false;
            }
        }
        
        return true;
    }
};

/*

x o x
o x o
x o x

*/