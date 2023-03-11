class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        
        for (vector<int>& row: grid) {
            sort(begin(row), end(row), greater<>());
        }
        
        for (int i = 0; i < size(grid); i++) {
            for (int j = 0; j < size(grid[i]); j++) {
                grid[0][j] = max(grid[0][j], grid[i][j]);
            }
        }
        
        return accumulate(begin(grid.front()), end(grid.front()), 0);
        
        return ans;
    }
};