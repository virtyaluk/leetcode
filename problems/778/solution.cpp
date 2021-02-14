typedef vector<vector<int>> vvi;

class Solution {
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = size(grid), lo = grid[0][0], hi = n * n - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (helper(grid, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
    bool helper(const vvi& g, int t) {
        int n = size(g);
        queue<pair<int, int>> q;
        vector<vector<bool>> seen(n, vector<bool>(n));
        
        q.push({0, 0});
        seen[0][0] = true;
        
        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            if (g[x][y] > t) {
                continue;
            }
            
            if (x == n - 1 and y == n - 1) {
                return true;
            }

            for (auto dir: dirs) {
                int nx = x + dir[0], ny = y + dir[1];

                if (nx >= 0 and nx < n and ny >= 0 and ny < n and not seen[nx][ny]) {
                    q.push({nx, ny});
                    seen[nx][ny] = true;
                }
            }
        }
        
        return false;
    }
};

/*

0 2
1 3

*/