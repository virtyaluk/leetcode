const int dirs[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ans = 0,
            m = size(maze),
            n = size(maze.back()),
            ox = entrance[0],
            oy = entrance[1];
        queue<pair<int, int>> q;
        
        q.push({ox, oy});
        maze[ox][oy] = '+';
        
        while (not empty(q)) {            
            for (int i = size(q); i > 0; i--) {
                auto [x, y] = q.front();
                q.pop();
                
                if (not x or x == m - 1 or not y or y == n - 1) {
                    if (!(ox == x and oy == y)) {
                        return ans;
                    }
                }
                
                for (auto dir: dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    
                    if (nx < 0 or nx >= m or ny < 0 or ny >= n or maze[nx][ny] != '.') {
                        continue;
                    }
                    
                    q.push({nx, ny});
                    maze[nx][ny] = '+';
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};