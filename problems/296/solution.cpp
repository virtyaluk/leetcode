class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int ans = 0, m = size(grid), n = size(grid.back()), midRow = 0, midCol = 0;
        vector<int> cols, rows;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        nth_element(begin(cols), begin(cols) + size(cols) / 2, end(cols));
        midRow = rows[size(rows) / 2];
        midCol = cols[size(cols) / 2];
        
        for (int i = 0; i < size(rows); i++) {
            ans += abs(cols[i] - midCol);
            ans += abs(rows[i] - midRow);
        }
        
        return ans;
    }
};