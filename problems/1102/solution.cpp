class Solution {
private:
    int dirs[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = size(grid),
            n = size(grid.back()),
            ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<tuple<int, int, int>> pq;
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        while (not empty(pq)) {
            auto [score, x, y] = pq.top();
            pq.pop();
            
            if (x == m - 1 and y == n - 1) {
                ans = max(ans, score);
                continue;
            }
            
            for (auto dir: dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                
                if (nx < 0 or nx >= m or ny < 0 or ny >= n or visited[nx][ny]) {
                    continue;
                }
                
                pq.push({min(score, grid[nx][ny]), nx, ny});
                visited[nx][ny] = true;
            }
        }
        
        return ans;
    }
};