class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = size(grid),
            n = size(grid.front()),
            ans = 0,
            dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}},
            memo[m][n][4][2];
        memset(memo, -1, sizeof(memo));

        function<int(int, int, int, bool, int)> dfs = [&](int cx, int cy, int dir, bool turn, int t) -> int {
            int nx = cx + dirs[dir][0],
                ny = cy + dirs[dir][1];
            
            if (nx < 0 or ny < 0 or nx >= m or ny >= n or grid[nx][ny] != t) {
                return 0;
            }

            if (memo[nx][ny][dir][turn] != -1) {
                return memo[nx][ny][dir][turn];
            }

            int maxStep = dfs(nx, ny, dir, turn, 2 - t);

            if (turn) {
                maxStep = fmax(maxStep, dfs(nx, ny, (dir + 1) % 4, false, 2 - t));
            }

            memo[nx][ny][dir][turn] = maxStep + 1;

            return maxStep + 1;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        ans = max(ans, dfs(i, j, dir, true, 2) + 1);
                    }
                }
            }
        }

        return ans;
    }
};