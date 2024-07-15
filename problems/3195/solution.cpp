class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l = INT_MAX, r = 0, t = INT_MAX, b = 0;
        
        for (int i = 0; i < size(grid); i++) {
            for (int j = 0; j < size(grid.front()); j++) {
                if (grid[i][j] == 1) {
                    l = min(l, j);
                    r = max(r, j);
                    t = min(t, i);
                    b = max(b, i);
                }
            }
        }
        
        return (r - l + 1) * (b - t + 1);
    }
};