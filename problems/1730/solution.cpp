class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.back().size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<tuple<int, int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    q.push({i, j, 0});
                    break;
                }
            }
        }

        while (not q.empty()) {
            auto [x, y, dist] = q.front();
            q.pop();
            
            if (x < 0 or x >= m or y < 0 or y >= n or visited[x][y] or grid[x][y] == 'X') {
                continue;
            }
            
            visited[x][y] = true;
            
            if (grid[x][y] == '#') {
                return dist;
            }
            
            q.push({x - 1, y, dist + 1});
            q.push({x + 1, y, dist + 1});
            q.push({x, y - 1, dist + 1});
            q.push({x, y + 1, dist + 1});
        }
        
        return -1;
    }
};