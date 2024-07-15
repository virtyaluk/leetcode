class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int m = size(grid),
            n = size(grid.back());
        vector<tuple<int, int, int>> v;
        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> rows(m),
            cols(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back({grid[i][j], i, j});
            }
        }
        
        sort(begin(v), end(v));
        
        for (auto& [val, i, j]: v) {
            ans[i][j] = max(rows[i], cols[j]) + 1;
            rows[i] = cols[j] = ans[i][j];
        }
        
        return ans;
    }
};