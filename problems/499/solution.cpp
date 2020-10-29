tuple<int, int, char> dirs[4] = {
    {-1, 0, 'u'},
    {1, 0, 'd'},
    {0, 1, 'r'},
    {0, -1, 'l'}
};

class Solution {
private:
    pair<int, int> roll(vector<vector<int>>& maze, int x, int y, int dx, int dy, vector<int>& hole) {
        int m = size(maze), n = size(maze.back());
        
        while (true) {
            int nx = x + dx, ny = y + dy;
            
            if (nx < 0 or nx >= m or ny < 0 or ny >= n or maze[nx][ny] == 1) {
                break;
            }
            
            x = nx;
            y = ny;
            
            if (x == hole[0] and y == hole[1]) {
                break;
            }
        }
        
        return {x, y};
    }

public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = size(maze), n = size(maze.back());
        string ans = "impossible";
        vector<vector<pair<int, string>>> visited(m, vector<pair<int, string>>(n, {INT_MAX, ""}));
        queue<tuple<int, int, int, string>> q({
            {ball[0], ball[1], 0, ""}
        });
        
        while (not empty(q)) {
            auto [x, y, dist, move] = q.front();
            q.pop();
            
            if (visited[x][y] <= make_pair(dist, move)) {
                continue;
            }
            
            visited[x][y] = {dist, move};
            
            if (x == hole[0] and y == hole[1]) {
                ans = move;
            }
            
            for (auto [dx, dy, dm]: dirs) {
                auto [nx, ny] = roll(maze, x, y, dx, dy, hole);
                int ndist = dist + abs(nx - x) + abs(ny - y);
                string nmove = move + dm;
                
                if (nx >= 0 and nx < m and ny >= 0 and ny < n and visited[nx][ny] > make_pair(ndist, nmove)) {
                    q.push({nx, ny, ndist, nmove});
                }
            }
        }
        
        return ans;
    }
};