class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        if (grid[0][0] == 1) {
            return 0;
        }
        
        grid[0][0] = 1;
        
        for (int row = 1; row < rows; row++) {
            grid[row][0] = grid[row][0] == 0 && grid[row - 1][0] == 1 ? 1 : 0;
        }
        
        for (int col = 1; col < cols; col++) {
            grid[0][col] = grid[0][col] == 0 && grid[0][col - 1] == 1 ? 1 : 0;
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (grid[i][j] == 0) {
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                } else {
                    grid[i][j] = 0;
                }
            }
        }
        
        return grid[rows - 1][cols - 1];
    }
    
    int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
        int ans = 0;
        
        bfs(obstacleGrid, 0, 0, ans);
        
        return ans;
    }
    
    void bfs(const vector<vector<int>>& g, const int x, const int y, int &ans) {
        if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] == 1) {
            return;
        }
        
        if (x == g.size() - 1 && y == g[0].size() - 1) {
            ans++;
            return;
        }
        
        bfs(g, x + 1, y, ans);
        bfs(g, x, y + 1, ans);
    }
};