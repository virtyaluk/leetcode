class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        unordered_map<int, int> count;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                
                for (int k = j + 1; k < n; k++) {
                    if (grid[i][k] == 0) {
                        continue;
                    } 
                    
                    int pos = j * 200 + k;
                    ans += count.find(pos) == count.end() ? 0 : count[pos];
                    count[pos]++;
                }
            }
        }
        
        return ans;
    }
};