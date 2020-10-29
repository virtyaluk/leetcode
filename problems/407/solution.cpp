class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        int ans = 0, m = size(heightMap), n = size(heightMap.back());
        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        
        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = visited[m - 1][j] = true;
        }
        
        while (not empty(pq)) {
            auto [height, x, y] = pq.top();
            pq.pop();
            
            for (auto dir: dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                
                if (nx < 0 or nx >= m or ny < 0 or ny >= n or visited[nx][ny]) {
                    continue;
                }
                
                ans += max(0, height - heightMap[nx][ny]);
                pq.push({max(heightMap[nx][ny], height), nx, ny});
                visited[nx][ny] = true;
            }
        }
        
        return ans;
    }
};