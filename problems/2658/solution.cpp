const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
private:
    int dfs(vector<vector<int>>& g, int i, int j) {
        int ans = 0;

        if (i < 0 or i >= size(g) or j < 0 or j >= size(g.front()) or g[i][j] == 0) {
            return 0;
        }

        ans += g[i][j];
        g[i][j] = 0;

        for (auto dir: dirs) {
            ans += dfs(g, i + dir[0], j + dir[1]);
        }

        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0; i < size(grid); i++) {
            for (int j = 0; j < size(grid.front()); j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }

        return ans;
    }
};