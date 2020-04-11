class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        for (int i = 0; i < size(grid); i++) {
            for (int j = 0; j < size(grid.back()); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    helper(grid, i, j);
                }
            }
        }
        
        return ans;
    }
    
    void helper(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 or x >= size(grid) or y < 0 or y >= size(grid.back()) or grid[x][y] != '1') {
            return;
        }
        
        grid[x][y] = '0';
        
        helper(grid, x + 1, y);
        helper(grid, x - 1, y);
        helper(grid, x, y + 1);
        helper(grid, x, y - 1);
    }
};