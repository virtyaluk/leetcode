class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0, n = size(points), connected = 0, i = 0;
        vector<bool> visited(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        function<int(int, int)> md = [&](int i, int j) {
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        
        while (++connected < n) {
            visited[i] = true;
            
            for (int j = 0; j < n; j++) {
                if (not visited[j]) {
                    pq.push({md(i, j), j});
                }
            }
            
            while (visited[pq.top().second]) {
                pq.pop();
            }
            
            ans += pq.top().first;
            i = pq.top().second;
            
            pq.pop();
        }
        
        return ans;
    }
    
    int minCostConnectPoints1(vector<vector<int>>& points) {
        int ans = 0, n = size(points), cnt = 0;
        vector<bool> visited(n);
        unordered_map<int, unordered_map<int, int>> g;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        function<int(int, int)> md = [&](int i, int j) {
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = md(i, j);
                
                g[i][j] = dist;
                g[j][i] = dist;
            }
        }
        
        pq.push({0, 0});
        
        while (not empty(pq)) {
            auto [dist, i] = pq.top();
            pq.pop();
            
            if (visited[i]) {
                continue;
            }
            
            visited[i] = true;
            ans += dist;
            cnt++;
            
            for (auto [j, nextDist]: g[i]) {
                pq.push({nextDist, j});
            }
            
            if (cnt >= n) {
                break;
            }
        }
        
        return ans;
    }
};