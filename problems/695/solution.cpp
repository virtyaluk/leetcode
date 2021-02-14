class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int ans = 0, m = grid.size(), n = grid[0].size();
        function<int(int, int)> findIslandArea = [&](int i, int j) {
            int area = 0;
            queue<pair<int, int>> q;
            
            q.push({i, j});
            
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                    continue;
                }
                
                area++;
                grid[x][y] = 0;
                
                q.push({x + 1, y});
                q.push({x - 1, y});
                q.push({x, y + 1});
                q.push({x, y - 1});
            }
            
            return area;
        };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, findIslandArea(i, j));
                }
            }
        }
        
        return ans;
    }
};