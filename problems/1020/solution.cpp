class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0,
            m = size(grid),
            n = size(grid.back());
        
        for (int i = 0; i < m; i++) {
            if (grid[i][0]) {
                dfs(grid, i, 0);
            }
            
            if (grid[i][n - 1]) {
                dfs(grid, i, n - 1);
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (grid[0][j]) {
                dfs(grid, 0, j);
            }
            
            if (grid[m - 1][j]) {
                dfs(grid, m - 1, j);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += grid[i][j];
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        
        q.push({i, j});
        
        while (not empty(q)) {
            auto [x, y] = q.front();
            q.pop();
            
            if (x < 0 or x >= size(grid) or y < 0 or y >= size(grid.back()) or grid[x][y] == 0) {
                continue;
            }
            
            grid[x][y] = 0;
            
            q.push({x + 1, y});
            q.push({x - 1, y});
            q.push({x, y + 1});
            q.push({x, y - 1});
        }
    }
};