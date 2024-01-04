const int dir[5] = {0, 1, 0, -1, 0};

class Solution {
private:
    bool check(const vector<vector<int>>& cells, const int& days, const int& row, const int& col) {
        vector<vector<int>> grid(row, vector<int>(col)),
            visited(row, vector<int>(col));
        bool ans = false;
        
        for (int i = 0; i <= days; i++) {
            vector<int> cell = cells[i];
            grid[cell[0] - 1][cell[1] - 1] = 1;
        }
        
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0 and visited[0][i] == 0) {
                ans |= dfs(grid, visited, 0, i, row, col);
            }
        }
        
        return ans;
    }
    
    bool dfs(const vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, const int& row, const int& col) {
        visited[x][y] = 1;
        
        if (row - 1 == x) {
            return true;
        }
        
        bool ans = false;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i],
                ny = y + dir[i + 1];
            
            if (nx >= 0 and nx < row and ny >= 0 and ny < col and !visited[nx][ny] and !grid[nx][ny]) {
                ans |= dfs(grid, visited, nx, ny, row, col);
            }
        }
        
        return ans;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 0,
            hi = size(cells) - 1,
            ans = 0;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            
            if (check(cells, mid, row, col)) {
                lo = mid + 1;
                ans = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans + 1;
    }
};