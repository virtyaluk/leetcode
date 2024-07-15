class Solution {
private:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& ans, int x, int y, int id) {
        if (x < 0 or x >= size(g) or y < 0 or y >= size(g[x]) or g[x][y] == 0) {
            return;
        }
        
        ans[id][0] = min(ans[id][0], x);
        ans[id][1] = min(ans[id][1], y);
        ans[id][2] = max(ans[id][2], x);
        ans[id][3] = max(ans[id][3], y);
        
        g[x][y] = 0;
        
        dfs(g, ans, x - 1, y, id);
        dfs(g, ans, x + 1, y, id);
        dfs(g, ans, x, y - 1, id);
        dfs(g, ans, x, y + 1, id);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        
        for (int i = 0, id = 0; i < size(land); i++) {
            for (int j = 0; j < size(land[i]); j++) {
                if (land[i][j] == 1) {
                    ans.push_back({i, j, i, j});
                    dfs(land, ans, i, j, id++);
                }
            }
        }
        
        return ans;
    }
};