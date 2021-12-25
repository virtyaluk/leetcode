class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int dirs[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        queue<tuple<int, int, int>> q;
        
        q.push({0, 0, 0});
        
        while (!q.empty()) {
            auto [x, y, dist] = q.front();
            q.pop();
            
            if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 0) {
                continue;
            }
            
            dist++;
            grid[x][y] = 1;
            
            if (x == n - 1 && y == n - 1) {
                return dist;
            }
            
            for (auto dir: dirs) {
                q.push({x + dir[0], y + dir[1], dist});
            }
        }
        
        return -1;
        
        // return ans == INT_MAX ? -1 : ans;
    }
};