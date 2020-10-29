typedef tuple<int, int, int> xyd;
const int dirs[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        int m = maze.size(), n = maze.back().size(), dx = dest[0], dy = dest[1];
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        function<bool(xyd, xyd)> cmp = [](const xyd& lhs, const xyd& rhs) {
            return get<2>(rhs) < get<2>(lhs);
        };
        priority_queue<xyd, vector<xyd>, decltype(cmp)> pq(cmp);
        
        dp[start[0]][start[1]] = 0;
        pq.push({start[0], start[1], 0});
        
        while (not pq.empty()) {
            auto [x, y, lastDist] = pq.top();
            pq.pop();
            
            for (auto dir: dirs) {
                int nx = x + dir[0], ny = y + dir[1], dist = 0;
                
                while (nx >= 0 and ny >= 0 and nx < m and ny < n and not maze[nx][ny]) {
                    nx += dir[0];
                    ny += dir[1];
                    dist++;
                }
                
                nx -= dir[0];
                ny -= dir[1];
                
                if (dp[x][y] + dist < dp[nx][ny]) {
                    dp[nx][ny] = dp[x][y] + dist;
                    pq.push({nx, ny, dp[dx][dy]});
                }
            }
        }
        
        return dp[dx][dy] == INT_MAX ? -1 : dp[dx][dy];
    }
    
    int shortestDistance1(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        int m = maze.size(), n = maze.back().size(), dx = dest[0], dy = dest[1];
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        dp[start[0]][start[1]] = 0;
        q.push({start[0], start[1]});
        
        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto dir: dirs) {
                int nx = x + dir[0], ny = y + dir[1], dist = 0;
                
                while (nx >= 0 and ny >= 0 and nx < m and ny < n and not maze[nx][ny]) {
                    nx += dir[0];
                    ny += dir[1];
                    dist++;
                }
                
                nx -= dir[0];
                ny -= dir[1];
                
                if (dp[x][y] + dist < dp[nx][ny]) {
                    dp[nx][ny] = dp[x][y] + dist;
                    q.push({nx, ny});
                }
            }
        }
        
        return dp[dx][dy] == INT_MAX ? -1 : dp[dx][dy];
    }
};