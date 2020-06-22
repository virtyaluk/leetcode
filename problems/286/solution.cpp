class Solution {
public:
    int dists[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() or rooms.back().empty()) {
            return;
        }
        
        int m = size(rooms), n = size(rooms.back());
        queue<tuple<int, int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (not rooms[i][j]) {
                    q.push({i, j, 1});
                }
            }
        }
        
        while (not q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();
            
            for (auto dist: dists) {
                int nx = x + dist[0], ny = y + dist[1];
                
                if (nx < 0 or nx >= m or ny < 0 or ny >= n or rooms[nx][ny] == -1 or rooms[nx][ny] == 0) {
                    continue;
                }
                
                if (d >= rooms[nx][ny]) {
                    continue;
                }
                
                rooms[nx][ny] = d;
                
                q.push({nx, ny, d + 1});
            }
        }
    }
};