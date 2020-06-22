class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int ans = 0, m = size(grid), n = size(grid.back()), rowHits = 0;
        vector<int> colHits(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (not j or grid[i][j - 1] == 'W') {
                    rowHits = 0;
                    
                    for (int k = j; k < n; k++) {
                        if (grid[i][k] == 'W') {
                            break;
                        } else if (grid[i][k] == 'E') {
                            rowHits++;
                        }
                    }
                }
                
                if (not i or grid[i - 1][j] == 'W') {
                    colHits[j] = 0;
                    
                    for (int k = i; k < m; k++) {
                        if (grid[k][j] == 'W') {
                            break;
                        } else if (grid[k][j] == 'E') {
                            colHits[j]++;
                        }
                    }
                }
                
                if (grid[i][j] == '0') {
                    ans = max(ans, rowHits + colHits[j]);
                }
            }
        }
        
        return ans;
    }
};