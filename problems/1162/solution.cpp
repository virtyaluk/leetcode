const int dirs[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int ans = 0, m = size(grid), n = size(grid.back());
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        
        while (not empty(q)) {
            ans++;
            
            for (int i = size(q); i > 0; i--) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto dir: dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    
                    if (nx < 0 or nx >= m or ny < 0 or ny >= n or grid[nx][ny]) {
                        continue;
                    }
                    
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return ans <= 1 ? -1 : ans - 1;
    }
};