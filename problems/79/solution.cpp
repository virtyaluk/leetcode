class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = size(board), n = size(board.back());
        
        function<bool(int, int, int)> dfs;
        
        dfs = [&](int i, int x, int y) {
            if (i >= size(word)) {
                return true;
            }

            if (x < 0 or x >= m or y < 0 or y >= n or board[x][y] != word[i]) {
                return false;
            }
            
            i++;
            char tmp = board[x][y];
            board[x][y] = '#';
            bool found = dfs(i, x + 1, y) or dfs(i, x - 1, y) or dfs(i, x, y + 1) or dfs(i, x, y - 1);
            
            board[x][y] = tmp;
            
            return found;
        };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(0, i, j)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};