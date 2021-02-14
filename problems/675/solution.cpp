class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (empty(forest) or empty(forest.front())) {
            return 0;
        }
        
        int m = size(forest), n = size(forest.back()), ans = 0;
        vector<vector<int>> trees;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }
        
        sort(begin(trees), end(trees));
        
        for (int i = 0, curRow = 0, curCol = 0; i < size(trees); i++) {
            int step = nextStep(forest, trees[i][1], trees[i][2], curRow, curCol);
            
            if (step == -1) {
                return -1;
            }
            
            ans += step;
            curRow = trees[i][1];
            curCol = trees[i][2];
        }
        
        return ans;
    }
    
    int nextStep(vector<vector<int>>& forest, int tx, int ty, int sx, int sy) {
        if (tx == sx and ty == sy) {
            return 0;
        }
        
        int m = size(forest), n = size(forest.back()), ans = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<int> dir = {-1, 0, 1, 0, -1};
        
        q.push({sx, sy});
        visited[sx][sy] = true;
        
        while (not empty(q)) {
            ans++;
            
            for (int qSize = size(q); qSize; qSize--) {
                auto [x, y] = q.front();
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nx = x + dir[i], ny = y + dir[i + 1];
                    
                    if (nx < 0 or nx >= m or ny < 0 or ny >= n or visited[nx][ny] or not forest[nx][ny]) {
                        continue;
                    }
                    
                    if (nx == tx and ny == ty) {
                        return ans;
                    }
                    
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        
        return -1;
    }
};