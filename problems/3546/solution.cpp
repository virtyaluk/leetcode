class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0,
            rows = size(grid),
            cols = size(grid.front()),
            cur = 0;
        vector<long long> r(rows),
            c(cols);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                total += grid[i][j];
                r[i] += grid[i][j];
                c[j] += grid[i][j];
            }
        }

        if (total % 2 != 0) {
            return false;
        }

        cur = 0;

        for (int i = 0; i < rows - 1; i++) {
            cur += r[i];

            if (cur * 2 == total) {
                return true;
            }
        }

        cur = 0;

        for (int i = 0; i < cols - 1; i++) {
            cur += c[i];

            if (cur * 2 == total) {
                return true;
            }
        }

        return false;
    }
};