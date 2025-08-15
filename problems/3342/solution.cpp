const int dirs[4][2] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        using State = tuple<int, int, int, int>;
        int n = size(moveTime),
            m = size(moveTime.front());
        vector<vector<bool>> visited(n, vector<bool>(m));
        priority_queue<State, vector<State>, greater<>> pq;
        
        pq.push({0, 0, 0, 0});
        visited[0][0] = true;

        while(not empty(pq)) {
            auto [timeSpentTillNow, moveNo, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 and y == m - 1) {
                return timeSpentTillNow;
            }
            
            for (auto dir: dirs) {
                int xCord = x + dir[0],
                    yCord = y + dir[1];

                if (xCord < 0 or xCord >=n or yCord<0 or yCord >=m or visited[xCord][yCord]) {
                    continue;
                }
                
                visited[xCord][yCord] = 1;
                int timeForNextHop = max(timeSpentTillNow, moveTime[xCord][yCord])+(moveNo%2+1);
                pq.push({timeForNextHop, moveNo + 1, xCord, yCord});
            }
        }

        return -1;
    }
};