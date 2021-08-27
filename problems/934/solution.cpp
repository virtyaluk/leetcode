class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestBridge(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid.back()), dist = 0;
        bool found = false;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (not found and grid[i][j] == 1) {
                    dfs(grid, i, j);
                    found = true;
                } else if (found and grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        while (not empty(q)) {
            for (int qlen = size(q) - 1; qlen >= 0; qlen--) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto dir: dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    
                    if (nx < 0 or nx >= m or ny < 0 or ny >= n or grid[nx][ny] == 1) {
                        continue;
                    }
                    
                    if (grid[nx][ny] == 2) {
                        return dist;
                    }
                    
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            
            dist++;
        }
        
        return -1;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 or x >= size(grid) or y < 0 or y >= size(grid.back()) or grid[x][y] != 1) {
            return;
        }
        
        grid[x][y] = 2;
        
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
};