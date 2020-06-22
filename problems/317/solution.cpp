class Solution {
public:
    int dists[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int shortestDistance(vector<vector<int>>& grid) {
        int ans = INT_MAX, m = size(grid), n = size(grid.back()), buildings = 0;
        unordered_map<int, unordered_map<int, int>> reach;
        vector<vector<int>> dist(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    buildings++;
                    bfs(grid, reach, dist, i, j);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (not grid[i][j] and reach[i][j] == buildings) {
                    ans = min(ans, dist[i][j]);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
    
    void bfs(const vector<vector<int>>& g,
             unordered_map<int, unordered_map<int, int>>& r,
             vector<vector<int>>& d,
             int i, int j) {
        int m = size(g), n = size(g.back()), level = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;
        
        q.push({i, j});
        
        while (not empty(q)) {
            level++;

            for (int qsize = size(q) - 1; qsize >= 0; qsize--) {
                auto [x, y] = q.front();
                q.pop();
                
                r[x][y]++;
                
                for (auto dist: dists) {
                    int nx = x + dist[0], ny = y + dist[1];
                    
                    if (nx >= 0 and nx < m and ny >= 0 and ny < n and g[nx][ny] == 0 and not visited[nx][ny]) {
                        visited[nx][ny] = true;
                        d[nx][ny] += level;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
};