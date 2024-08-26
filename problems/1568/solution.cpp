class Solution {
private:
    void dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 or i >= size(g) or j < 0 or j >= size(g.front()) or g[i][j] == 0) {
            return;
        }
        
        g[i][j] = 0;
        dfs(g, i + 1, j);
        dfs(g, i - 1, j);
        dfs(g, i, j + 1);
        dfs(g, i, j - 1);
    }
    
    int numIslands(vector<vector<int>> g) {
        int ans = 0;
        
        for (int i = 0; i < size(g); i++) {
            for (int j = 0; j < size(g[i]); j++) {
                if (g[i][j] == 1) {
                    ans++;
                    dfs(g, i, j);
                }
            }
        }
        
        return ans;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int islands = numIslands(grid);
        
        if (not islands or islands > 1) {
            return 0;
        }
        
        for (int i = 0; i < size(grid); i++) {
            for (int j = 0; j < size(grid[i]); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    islands = numIslands(grid);
                    
                    if (not islands or islands > 1) {
                        return 1;
                    }
                    
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};