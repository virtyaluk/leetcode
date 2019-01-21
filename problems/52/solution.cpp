class Solution {
public:
    int n;

    int totalNQueens(int n) {
        this->n = n;
        int ans = 0;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        unordered_set<int> diagonals, antiDiagonals, cols;
        
        backtrack(0, diagonals, antiDiagonals, cols, board, ans);
        
        return ans;
    }
    
    void backtrack(int row, unordered_set<int>& diagonals, unordered_set<int>& antiDiagonals, unordered_set<int>& cols, vector<vector<char>>& board, int& ans) {
        if (row == n) {
            ans++;
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