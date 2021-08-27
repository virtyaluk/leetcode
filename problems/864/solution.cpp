class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = size(grid), n = size(grid.back()), ans = 0, k = 0;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(pow(2, 6))));
        queue<tuple<int, int, int>> q;
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    q.push({i, j, 0});
                }
                
                if (isalpha(grid[i][j]) and isupper(grid[i][j])) {
                    k++;
                }
            }
        }
        
        while (not empty(q)) {
            for (int qsize = size(q); qsize > 0; qsize--) {
                auto [x, y, curK] = q.front();
                q.pop();
                
                if (curK == ((1 << k) - 1)) {
                    return ans;
                }
                
                for (auto dir: dirs) {
                    int nx = x + dir[0],
                        ny = y + dir[1],
                        nk = curK;
                    
                    if (nx < 0 or nx >= m or ny < 0 or ny >= n or grid[nx][ny] == '#') {
                        continue;
                    }
                    
                    if (islower(grid[nx][ny])) {
                        nk = curK | (1 << (grid[nx][ny] - 'a'));
                    } else if (isupper(grid[nx][ny])) {
                        if (not (curK & (1 << (grid[nx][ny] - 'A')))) {
                            continue;
                        }
                    }
                    
                    if (not visited[nx][ny][nk]) {
                        visited[nx][ny][nk] = true;
                        q.push({nx, ny, nk});
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};