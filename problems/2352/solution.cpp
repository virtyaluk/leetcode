class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        vector<int> row, col;
        map<vector<int>, int> m;
        
        for (int i = 0; i < size(grid); i++) {
            for (int j = 0; j < size(grid.back()); j++) {
                row.push_back(grid[i][j]);
            }
            
            m[row]++;
            row.clear();
        }
        
        for (int j = 0; j < size(grid.back()); j++) {
            for (int i = 0; i < size(grid); i++) {
                col.push_back(grid[i][j]);
            }
            
            ans += m[col];
            col.clear();
        }
        
        return ans;
    }
};