const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
private:
    bool isValid(int row, int col, int m, int n) {
        return row >= 0 and row < m and col >= 0 and col < n;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m = size(grid),
            n = size(grid.front());
        deque<pair<int, int>> q;  // for the pair, the first element is the cell position, the second is the path cost to this cell
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        q.push_front({0, 0});
        cost.front().front() = 0;
        
        while(not empty(q))
        {
            auto [row, col] = q.front(); 
            q.pop_front();

            for (int dir = 0; dir < 4; dir++) {
                int nextRow = row + dirs[dir][0],
                    nextCol = col + dirs[dir][1],
                    nextCost = (grid[row][col] != (dir + 1)) ? 1 : 0;
                
                if (isValid(nextRow, nextCol, m, n) and cost[row][col] + nextCost < cost[nextRow][nextCol]) {
                    cost[nextRow][nextCol] = cost[row][col] + nextCost;

                    if (nextCost == 1) {
                        q.push_back({nextRow, nextCol});
                    } else {
                        q.push_front({nextRow, nextCol});
                    }
                }
            }
        }
    
        return cost.back().back();
    }
};