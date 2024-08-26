const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        
        for (int step = 1, dir = 0; ans.size() < rows * cols;) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < step; j++) {
                    if (rStart >= 0 and rStart < rows and cStart >= 0 and cStart < cols) {
                        ans.push_back({rStart, cStart});
                    }
                    
                    rStart += dirs[dir][0];
                    cStart += dirs[dir][1];
                }
                
                dir = (dir + 1) % 4;
            }
            
            step++;
        }
        
        return ans;
    }
};