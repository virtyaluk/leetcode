class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = size(isWater), n = size(isWater.back()), height = 1;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                isWater[i][j] = isWater[i][j] == 1 ? 0 : -1;
                
                if (isWater[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        while (not empty(q)) {
            for (int qLen = size(q) - 1; qLen >= 0; qLen--) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto dir: dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    
                    if (nx < 0 or nx >= m or ny < 0 or ny >= n or isWater[nx][ny] != -1) {
                        continue;
                    }
                    
                    isWater[nx][ny] = height;
                    q.push({nx, ny});
                }
            }
            
            height++;
        }
        
        return isWater;
    }
};