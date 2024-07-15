int dirs[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

class Solution {
private:
    int dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 or i >= size(g) or j < 0 or j >= size(g.front()) or not g[i][j]) {
            return 0;
        }
        
        int ans = 0,
            prev = g[i][j];
        g[i][j] = 0;
        
        for (auto nextDir: dirs) {
            ans = max(ans, dfs(g, i + nextDir[0], j + nextDir[1]));
        }
        
        g[i][j] = prev;
        
        return ans + prev;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        
        for (int i = 0; i < size(grid); i++) {
            for (int j = 0; j < size(grid[i]); j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        
        return ans;
    }
};