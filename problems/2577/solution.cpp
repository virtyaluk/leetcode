const int dirs[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

class Solution {
private:
    bool isValid(vector<vector<bool>>& visited, int row, int col) {
        return row >= 0 and col >= 0 and row < size(visited) and col < size(visited.front()) and not visited[row][col];
    }

public:
    int minimumTime(vector<vector<int>>& g) {
        if (g.front()[1] > 1 and g[1].front() > 1) {
            return -1;
        }
        
        int rows = size(g),
            cols = size(g.front());
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        pq.push({g.front().front(), 0, 0});
        
        while (not empty(pq)) {
            auto [time, row, col] = pq.top();
            pq.pop();
            
            if (row == rows - 1 and col == cols - 1) {
                return time;
            }
            
            if (visited[row][col]) {
                continue;
            }
            
            visited[row][col] = true;
            
            for (auto& dir: dirs) {
                int nextRow = dir[0] + row,
                    nextCol = dir[1] + col;
                
                if (!isValid(visited, nextRow, nextCol)) {
                    continue;
                }
                
                int waitTime = ((g[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0,
                    nextTime = max(g[nextRow][nextCol] + waitTime, time + 1);
                
                pq.push({nextTime, nextRow, nextCol});
            }
        }
        
        return -1;
    }
};