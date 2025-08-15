const int DIRS[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = size(moveTime),
            m = size(moveTime.front()),
            ans = INT_MAX;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        // moveTime[0][0] = -1;

        while (not empty(pq)) {
            auto [t, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 and y == m - 1) {
                ans = min(ans, t);
            }

            for (auto dir: DIRS) {
                int nextX = x + dir[0],
                    nextY = y + dir[1];
                
                if (nextX < 0 or nextX >= n or nextY < 0 or nextY >= m or moveTime[nextX][nextY] < 0) {
                    continue;
                }

                if (t < moveTime[nextX][nextY]) {
                    pq.push({1 + moveTime[nextX][nextY], nextX, nextY});
                } else {
                    pq.push({1 + t, nextX, nextY});
                }
                
                moveTime[nextX][nextY] = -1;
            }
        }

        return ans;
    }
};