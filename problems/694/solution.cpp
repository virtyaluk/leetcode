class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int ans = 0;
        set<set<int>> seen;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    set<int> shape = dfs(grid, i, j);
                    
                    if (seen.find(shape) == seen.end()) {
                        ans++;
                        seen.insert(shape);
                    }
                }
            }
        }
        
        return ans;
    }
    
    set<int> dfs(vector<vector<int>>& g, int i, int j) {
        set<int> shape;
        queue<tuple<int, int, int>> q;
        
        q.push({i, j, 1});
        
        while (!q.empty()) {
            auto [x, y, k] = q.front();
            q.pop();
            
            if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] == 0) {
                continue;
            }
            
            shape.insert(k);
            g[x][y] = 0;
            
            q.push({x + 1, y, k + 50});
            q.push({x - 1, y, k - 50});
            q.push({x, y + 1, k + 1});
            q.push({x, y - 1, k - 1});
        }
        
        return shape;
    }
};