const int dirs[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = size(grid),
            cols = size(grid.front()),
            total = 0;
        vector<int> ans(size(queries));
        vector<pair<int, int>> sq;
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        for (int i = 0; i < size(queries); i++) {
            sq.push_back({queries[i], i});
        }

        sort(begin(sq), end(sq));

        pq.push({grid.front().front(), 0, 0});
        visited[0][0] = true;

        for (auto [qval, idx] : sq) {
            while (not empty(pq) and get<0>(pq.top()) < qval) {
                auto [_, currentRow, currentCol] = pq.top();
                pq.pop();
                
                total++;

                for (auto [rowOffset, colOffset] : dirs) {
                    int nextRow = currentRow + rowOffset,
                        nextCol = currentCol + colOffset;

                    if (nextRow >= 0 and nextCol >= 0 and nextRow < rows and
                        nextCol < cols and !visited[nextRow][nextCol]) {
                        pq.push({grid[nextRow][nextCol], nextRow, nextCol});
                        visited[nextRow][nextCol] = true;
                    }
                }
            }
    
            ans[idx] = total;
        }

        return ans;
    }
};