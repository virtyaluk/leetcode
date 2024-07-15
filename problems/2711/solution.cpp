class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = size(grid),
            n = size(grid.front());
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                unordered_set<int> topLeft,
                    bottomRight;
                
                for (int x = i - 1, y = j - 1; x >= 0 and y >= 0;) {
                    topLeft.insert(grid[x--][y--]);
                }
                
                for (int x = i + 1, y = j + 1; x < m and y < n;) {
                    bottomRight.insert(grid[x++][y++]);
                }
                
                ans[i][j] = abs((int) (size(topLeft) - size(bottomRight)));
            }
        }
        
        return ans;
    }
};