class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for (int i = 0; i < size(grid); i++) {
            if (accumulate(begin(grid[i]), end(grid[i]), 0) == size(grid) - 1) {
                return i;
            }
        }
        
        return -1;
    }
};