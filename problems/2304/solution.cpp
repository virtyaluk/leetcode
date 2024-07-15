class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = size(grid),
            n = size(grid.front());
        
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int minDist = INT_MAX,
                    curDist = INT_MAX;
                
                for (int k = 0; k < n; k++) {
                    curDist = grid[i + 1][k] + moveCost[grid[i][j]][k];
                    minDist = min(minDist, curDist);
                }
                
                grid[i][j] += minDist;
            }
        }
        
        return *min_element(begin(grid.front()), end(grid.front()));
    }
};