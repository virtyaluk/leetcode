class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> hor(9, vector<bool>(10)),
            vert(9, vector<bool>(10)),
            group(9, vector<bool>(10));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0',
                        k = i / 3 * 3 + j / 3;
                    
                    if (hor[i][num] or vert[j][num] or group[k][num]) {
                        return false;
                    }
                    
                    hor[i][num] = vert[j][num] = group[k][num] = true;
                }
            }
        }
        
        return true;
    }
};