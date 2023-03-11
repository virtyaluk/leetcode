const int MOD = 1e9 + 7;
const int dirs[4][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = size(grid),
            m = size(grid.front()),
            ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, 1));
        vector<tuple<int, int, int>> cells;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }
        
        sort(begin(cells), end(cells));
        
        for (const auto [ignore, x, y]: cells) {
            for (const auto dir: dirs) {
                int nx = x + dir[0],
                    ny = y + dir[1];
                
                if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] > grid[x][y]) {
                    dp[nx][ny] += dp[x][y];
                    dp[nx][ny] %= MOD;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += dp[i][j];
                ans %= MOD;
            }
        }
        
        return ans;
    }
};