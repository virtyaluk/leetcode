class Solution {
private:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, - 1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() or matrix.back().empty()) {
            return {};
        }
        
        
        int m = matrix.size(), n = matrix.back().size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacificReachable(m, vector<bool>(n)), atlinticReachable(m, vector<bool>(n));
        queue<pair<int, int>> pacificq, atlanticq;
        
        for (int i = 0; i < m; i++) {
            pacificq.push({i, 0});
            atlanticq.push({i, n - 1});
        }
        
        for (int i = 0; i < n; i++) {
            pacificq.push({0, i});
            atlanticq.push({m - 1, i});
        }
        
        proccessQueue(matrix, pacificq, pacificReachable);
        proccessQueue(matrix, atlanticq, atlinticReachable);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificReachable[i][j] and atlinticReachable[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
    
    void proccessQueue(vector<vector<int>>& mat, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        int m = mat.size(), n = mat.back().size();
        
        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            if (visited[x][y]) {
                continue;
            }
            
            visited[x][y] = true;
            
            for (auto dir: dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                
                if (nx < 0 or nx >= m or ny < 0 or ny >= n or mat[nx][ny] < mat[x][y]) {
                    continue;
                }
                
                q.push({nx, ny});
            }
        }
    }
};