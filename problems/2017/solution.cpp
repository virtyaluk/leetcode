class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long int ans = LLONG_MAX,
            topSum = accumulate(begin(grid.front()), end(grid.front()), 0ll),
            bottomSum = 0;
        
        for (int i = 0; i < size(grid.front()); i++) {
            topSum -= grid[0][i];
            ans = min(ans, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }
        
        return ans;
    }
};