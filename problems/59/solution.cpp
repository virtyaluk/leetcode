class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int curN = 1, d = 0, x = 0, y = 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (curN <= n*n) {
            ans[x][y] = curN++;
            
            int r = floorMod(x + dir[d][0], n),
                c = floorMod(y + dir[d][1], n);
            
            if (ans[r][c] != 0) {
                d = (d + 1) % 4;
            }
            
            x += dir[d][0];
            y += dir[d][1];
        }
        
        return ans;
    }
    
    int floorMod(int x, int y) {
        return ((x % y) + y) % y;
    }
};