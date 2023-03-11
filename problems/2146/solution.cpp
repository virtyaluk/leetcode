const int dists[4][2] = {
    {1, 0},
    {-1, 0},
    {0, -1},
    {0, 1}
};

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = size(grid),
            n = size(grid.back());
        queue<tuple<int, int, int, int>> q; // x, y, price, dist
        vector<vector<int>> candidates, ans;
        
        q.push({start[0], start[1], grid[start[0]][start[1]], 0});
        grid[start[0]][start[1]] = 0;
        
        while (not empty(q)) {
            auto [x, y, price, dist] = q.front();
            q.pop();
            
            if (price >= pricing[0] and price <= pricing[1]) {
                candidates.push_back({dist, price, x, y});
            }
            
            dist++;
            
            for (auto d: dists) {
                int nx = x + d[0], ny = y + d[1];
                
                if (nx < 0 or nx >= m or ny < 0 or ny >= n or grid[nx][ny] == 0) {
                    continue;
                }
                
                q.push({nx, ny, grid[nx][ny], dist});
                grid[nx][ny] = 0;
            }
        }
        
        sort(begin(candidates), end(candidates));
        
        for (int i = 0; i < min(1 * k, (int) size(candidates)); i++) {
            ans.push_back({candidates[i][2], candidates[i][3]});
        }
        
        return ans;
    }
};