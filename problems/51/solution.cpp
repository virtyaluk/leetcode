class Solution {
public:
    int n;
    
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        unordered_set<int> diagonals, antiDiagonals, cols;
        
        backtrack(0, diagonals, antiDiagonals, cols, board, ans);
        
        return ans;
    }
    
    vector<string> createBoard(vector<vector<char>>& state) {
        vector<string> board;
        
        for (int row = 0; row < n; row++) {
            string curRow(begin(state[row]), end(state[row]));
            
            board.push_back(curRow);
        }
        
        return board;
    }
    
    void backtrack(int row, unordered_set<int>& diagonals, unordered_set<int>& antiDiagonals, unordered_set<int>& cols, vector<vector<char>>& board, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(createBoard(board));
            return;
        }
        
        for (int col = 0; col < n; col++) {
            int curDiagonal = row - col,
                curAntiDiagonal = row + col;
            
            if (cols.count(col) or diagonals.count(curDiagonal) or antiDiagonals.count(curAntiDiagonal)) {
                continue;
            }
            
            cols.insert(col);
            diagonals.insert(curDiagonal);
            antiDiagonals.insert(curAntiDiagonal);
            board[row][col] = 'Q';
            
            backtrack(row + 1, diagonals, antiDiagonals, cols, board, ans);
            
            cols.erase(col);
            diagonals.erase(curDiagonal);
            antiDiagonals.erase(curAntiDiagonal);
            board[row][col] = '.';
        }
    }
};