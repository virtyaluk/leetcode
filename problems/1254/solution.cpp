class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 && dfs(grid, i, j)) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    bool dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
            return false;
        }
        
        if (grid[x][y] == 1) {
            return true;
        }
        
        grid[x][y] = 1;
        
        bool ans = true;
        
        for (auto d: dir) {
            ans = ans & dfs(grid, x + d[0], y + d[1]);
        }
        
        return ans;
    }
};