class Solution {
private:
    int ans;
    vector<vector<int>> grid;
public:
    int uniquePathsIII(vector<vector<int>>& g) {
        int startX = 0, startY = 0, walkableSquares = 0;
        grid = g;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                
                if (grid[i][j] >= 0) {
                    walkableSquares++;
                }
            }
        }
        
        backtrack(startX, startY, walkableSquares);
        
        return ans;
    }
    
    void backtrack(int x, int y, int walkableSquares) {
        if (grid[x][y] == 2 && walkableSquares == 1) {
            ans++;
            return;
        }
        
        int temp = grid[x][y];
        grid[x][y] = -4;
        walkableSquares--;
        
        int dirs[4][2] = {{0,1 }, {0, -1}, {1, 0}, {-1, 0}};
        
        for (auto [xOffset, yOffset]: dirs) {
            int newX = x + xOffset, newY = y + yOffset;
            
            if (newX < 0 || newX >= grid.size()) {
                continue;
            }
            
            if (newY < 0 || newY >= grid[newX].size()) {
                continue;
            }
            
            if (grid[newX][newY] < 0) {
                continue;
            }
            
            backtrack(newX, newY, walkableSquares);
        }
        
        grid[x][y] = temp;
    }
};