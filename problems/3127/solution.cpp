class Solution {
private:
    bool isPossible(vector<vector<char>>& grid, int i, int j) {
        int W = 0,
        B = 0;
        
        for (int x = i; x < i + 2; x++) {
            for (int y = j; y < j + 2; y++) {
                if (grid[x][y] == 'W') {
                    W++;
                } else {
                    B++;
                }
            }
        }
        
        if (W > 2 or B > 2) {
            return true;
        }

        return false;
    }
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n = size(grid);
        
        for (int i = 0; i <= n - 2; i++) {
            for (int j = 0; j <= n - 2; j++) {
                if (isPossible(grid, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};