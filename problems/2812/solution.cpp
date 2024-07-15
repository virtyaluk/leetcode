const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
private:
    bool isValidCell(vector<vector<int>>& mat, int i, int j) {
        int n = mat.size();
        
        return i >= 0 and j >= 0 and i < n and j < n;
    }
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = size(grid);
        queue<pair<int, int>> multiSourceQueue;
        priority_queue<vector<int>> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    multiSourceQueue.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        while (not empty(multiSourceQueue)) {
            int sz = size(multiSourceQueue);
            
            while (sz-- > 0) {
                auto curr = multiSourceQueue.front();
                multiSourceQueue.pop();
                
                for (auto& d : dir) {
                    int di = curr.first + d[0],
                        dj = curr.second + d[1],
                        val = grid[curr.first][curr.second];
                    
                    if (isValidCell(grid, di, dj) and grid[di][dj] == -1) {
                        grid[di][dj] = val + 1;
                        multiSourceQueue.push({di, dj});
                    }
                }
            }
        }

        
        pq.push(vector<int>{grid[0][0], 0, 0});
        grid[0][0] = -1;

        while (not empty(pq)) {
            auto curr = pq.top();
            pq.pop();

            if (curr[1] == n - 1 and curr[2] == n - 1) {
                return curr[0];
            }

            for (auto& d : dir) {
                int di = d[0] + curr[1],
                    dj = d[1] + curr[2];
                
                if (isValidCell(grid, di, dj) and grid[di][dj] != -1) {
                    pq.push(vector<int>{min(curr[0], grid[di][dj]), di, dj});
                    grid[di][dj] = -1;
                }
            }
        }

        return -1;
    }
};