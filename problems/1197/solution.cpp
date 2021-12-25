class Solution {
private:
    int dirs[8][2] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
    
public:
    int minKnightMoves(int tx, int ty) {
        int ans = 0;
        vector<vector<int>> visited(302, vector<int>(302, -1));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = 0;
        tx = abs(tx), ty = abs(ty);
        
        while (not q.empty()) {
            if (visited[tx][ty] != -1) {
                return visited[tx][ty];
            }
            
            auto [x, y] = q.front();
            q.pop();
            
            for (auto dir: dirs) {
                int nx = abs(x + dir[0]), ny = abs(y + dir[1]);
                
                if (visited[nx][ny] == -1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return -1;
    }
};