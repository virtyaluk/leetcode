const int dirs[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

class Solution {
private:
    bool isValid(vector<vector<int>>& g, int row, int col) {
        return row >= 0 and col >= 0 and row < size(g) and col < size(g.front());
    }
public:
    int minimumObstacles(vector<vector<int>>& g) {
        int m = size(g),
            n = size(g.back());
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        deque<tuple<int, int, int>> dq;
        
        dp.front().front() = 0;
        dq.push_back({0, 0, 0});
        
        while (not empty(dq)) {
            auto [obst, row, col] = dq.front();
            dq.pop_front();
            
            for (auto& dir: dirs) {
                int nextRow = row + dir[0],
                    nextCol = col + dir[1];
                
                if (isValid(g, nextRow, nextCol) and dp[nextRow][nextCol] == INT_MAX) {
                    if (g[nextRow][nextCol] == 1) {
                        dp[nextRow][nextCol] = obst + 1;
                        dq.push_back({obst + 1, nextRow, nextCol});
                    } else {
                        dp[nextRow][nextCol] = obst;
                        dq.push_front({obst, nextRow, nextCol});
                    }
                }
            }
        }
        
        return dp.back().back();
    }
};