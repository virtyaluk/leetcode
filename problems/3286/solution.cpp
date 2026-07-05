static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = size(grid),
            n = size(grid.front());
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> q;

        q.emplace_front(0, 0);
        dis.front().front() = grid.front().front();

        while (not empty(q)) {
            auto [cx, cy] = q.front();
            q.pop_front();

            if (cx == m - 1 and cy == n - 1) {
                return true;
            }

            for (auto& [dx, dy]: dirs) {
                int nx = cx + dx,
                    ny = cy + dy;
                
                if (nx < 0 or ny < 0 or nx >= m or ny >= n) {
                    continue;
                }

                int cost = dis[cx][cy] + grid[nx][ny];

                if (cost >= health) {
                    continue;
                }

                if (cost < dis[nx][ny]) {
                    dis[nx][ny] = cost;

                    if (grid[nx][ny] == 0) {
                        q.emplace_front(nx, ny);
                    } else {
                        q.emplace_back(nx, ny);
                    }
                }
            }
        }

        return false;
    }
};