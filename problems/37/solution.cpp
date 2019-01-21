class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, bool>> hor(9), vert(9), group(9);
        function<bool(int, int)> solve = [&](int i, int j) {
            if (i == 9) {
                return true;
            }
            
            if (j == 9) {
                return solve(i + 1, 0);
            }
            
            if (board[i][j] != '.') {
                return solve(i, j + 1);
            }
            
            int k = i / 3 * 3 + j / 3;
            
            for (char num = '1'; num <= '9'; num++) {
                if (not hor[i][num] and not vert[j][num] and not group[k][num]) {
                    hor[i][num] = vert[j][num] = group[k][num] = true;
                    board[i][j] = num;
                    
                    if (solve(i, j + 1)) {
                        return true;
                    }
                    
                    hor[i][num] = vert[j][num] = group[k][num] = false;
                    board[i][j] = '.';
                }
            }
            
            return false;
        };
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char ch = board[i][j];
                    int k = i / 3 * 3 + j / 3;
                    hor[i][ch] = vert[j][ch] = group[k][ch] = true;
                }
            }
        }
        
        solve(0, 0);
    }
};