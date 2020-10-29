class Solution {
private:
    int dirx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
    int diry[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
    
    bool isSafe(int x, int y, int m, int n) {
        return x >= 0 and x < m and y >= 0 and y < n;
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int cx = click.front(),
            cy = click.back();
        
        if (board[cx][cy] == 'M') {
            board[cx][cy] = 'X';
            
            return board;
        }
        
        queue<pair<int, int>> q;
        int m = size(board),
            n = size(board.front());
        
        q.push({cx, cy});
        
        while (not empty(q)) {
            for (int qLen = size(q); qLen > 0; qLen--) {
                auto [r, c] = q.front();
                int cnt = 0;
                
                q.pop();
                
                for (int i = 0; i < 8; i++) {
                    int x = r + dirx[i],
                        y = c + diry[i];
                    cnt += isSafe(x, y, m, n) and board[x][y] == 'M';
                }
                
                if (cnt) {
                    board[r][c] = '0' + cnt;
                } else {
                    board[r][c] = 'B';
                    
                    for (int i = 0; i < 8; i++) {
                        int x = r + dirx[i],
                            y = c + diry[i];
                        
                        if (isSafe(x, y, m, n) and board[x][y] == 'E') {
                            board[x][y] = 'B';
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        
        return board;
    }
};