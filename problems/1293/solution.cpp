class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = size(grid), n = size(grid.back());
        
        if (m == 1 and n == 1) {
            return 0;
        }
        
        if (m - 1 + n - 1 <= k) {
            return m - 1 + n - 1;
        }
        
        queue<tuple<int, int, int, int>> q; // x, y, k, steps
        unordered_map<int, unordered_map<int, unordered_map<int, bool>>> visited;
        
        q.push({0, 0, k, 0});
        visited[0][0][k] = true;
        
        while (not empty(q)) {
            auto [x, y, k, steps] = q.front();
            q.pop();
            
            for (auto dir: dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                
                if (nx < 0 or nx >= m or ny < 0 or ny >= n) {
                    continue;
                }
                
                if (grid[nx][ny] == 1 and k > 0 and not visited[nx][ny][k - 1]) {
                    q.push({nx, ny, k - 1, steps + 1});
                    visited[nx][ny][k - 1] = true;
                }
                
                if (grid[nx][ny] == 0 and not visited[nx][ny][k]) {
                    if (nx == m - 1 and ny == n - 1) {
                        return steps + 1;
                    }
                    
                    q.push({nx, ny, k, steps + 1});
                    visited[nx][ny][k] = true;
                }
            }
        }
        
        return -1;
    }
};