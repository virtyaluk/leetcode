class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        vector<int> dr = {0, 1, 0, -1},
            dc = {1, 0, -1, 0};
        int n = size(grid),
            ans = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] > 0) {
                    ans += 2;
    
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k],
                            nc = c + dc[k],
                            nv = 0;

                        if (0 <= nr and nr < n and 0 <= nc and nc < n) {
                            nv = grid[nr][nc];
                        }

                        ans += max(grid[r][c] - nv, 0);
                    }
                }
            }
        }

        return ans;
    }
};