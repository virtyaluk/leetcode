typedef tuple<int, int, int> cell;

class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        auto compCells = [](const cell& lhs, const cell& rhs) {
            return get<2>(lhs) > get<2>(rhs);
        };
        auto isValid = [&](int i, int j) {
            return i >= 0 && i <= m - 1 && j >= 0 && j <= n - 1;
        };
        
        vector<vector<int>> difs(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<cell, vector<cell>, decltype(compCells)> q(compCells);
        
        difs[0][0] = 0;
        q.push({0, 0, 0});
        
        while (!q.empty()) {
            auto [x, y, ignore] = q.top();
            q.pop();
            
            visited[x][y] = true;
            
            for (const auto& dir: dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                
                if (isValid(nx, ny) && !visited[nx][ny]) {
                    int curDif = abs(heights[nx][ny] - heights[x][y]);
                    int maxDif = max(curDif, difs[x][y]);
                    
                    if (difs[nx][ny] > maxDif) {
                        difs[nx][ny] = maxDif;
                        q.push({nx, ny, maxDif});
                    }
                }
            }
        }
        
        return difs[m - 1][n - 1];
    }
};