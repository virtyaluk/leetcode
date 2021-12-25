class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int rows = size(grid), cols = size(grid.front());
        
        for (int i = 0; i < cols; i++) {
            int curRow = 0, curCell = i;
            
            while (curRow < rows) {
                if (grid[curRow][curCell] == 1) {
                    if (curCell + 1 == cols or grid[curRow][curCell + 1] == -1) {
                        ans.push_back(-1);
                        break;
                    }
                    
                    curCell++;
                } else if (grid[curRow][curCell] == -1) {
                    if (curCell == 0 or grid[curRow][curCell - 1] == 1) {
                        ans.push_back(-1);
                        break;
                    }
                    
                    curCell--;
                }
                
                curRow++;
            }
            
            if (curRow == rows) {
                ans.push_back(curCell);
            }
        }
        
        return ans;
    }
};