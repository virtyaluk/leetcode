class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        
        for (int i = 0; i < size(grid2); i++) {
            for (int j = 0; j < size(grid2.back()); j++) {
                if (grid2[i][j]) {
                    ans += dfs(grid1, grid2, i, j);
                }
            }
        }
        
        return ans;
    }
    
    bool dfs(
        vector<vector<int>>& grid1,
        vector<vector<int>>& grid2,
        int i,
        int j
    ) {
        bool ans = true;
        queue<pair<int, int>> q;
        
        q.push({i, j});
        
        while (not empty(q)) {
            auto [x, y] = q.front();
            q.pop();
            
            if (x < 0 or x >= size(grid2) or y < 0 or y >= size(grid2.back()) or grid2[x][y] != 1) {
                continue;
            }
            
            grid2[x][y] = 0;
            
            if (not grid1[x][y]) {
                ans = false;
            }
            
            q.push({x + 1, y});
            q.push({x - 1, y});
            q.push({x, y + 1});
            q.push({x, y - 1});
        }
        
        return ans;
    }
};