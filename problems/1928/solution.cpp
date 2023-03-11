class Solution {
private:
    vector<vector<int>> graph[1001];
    
    int dijkstra(
            int src,
            int dest,
            int maxTime,
            vector<int>& cost,
            vector<int>& time) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        pq.push({cost[src], time[src], src});
        
        while (not empty(pq)) {
            auto [c, t, v] = pq.top();
            pq.pop();
            
            for (int i = 0; i < size(graph[v]); i++) {
                if (t + graph[v][i][1] <= maxTime) {
                    if (cost[graph[v][i][0]] > c + graph[v][i][2]) {
                        cost[graph[v][i][0]] = c + graph[v][i][2];
                        
                        time[graph[v][i][0]] = t + graph[v][i][1];
                        pq.push({cost[graph[v][i][0]], time[graph[v][i][0]], graph[v][i][0]});
                    } else if (time[graph[v][i][0]] > t + graph[v][i][1]) {
                        time[graph[v][i][0]] = t + graph[v][i][1];
                        pq.push({c + graph[v][i][2], time[graph[v][i][0]], graph[v][i][0]});
                    }
                }
            }
        }
        
        return cost[dest];
    }
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        int n = size(fee), ans = 0;
        vector<int> cost(n, INT_MAX),
            time(n, INT_MAX);
        
        for (const vector<int>& edge: edges) {
            int x = edge[0],
                y = edge[1],
                t = edge[2];
    
            graph[x].push_back({y, t, fee[y]});
            graph[y].push_back({x, t, fee[x]});
        }
        
        cost[0] = fee[0];
        time[0] = 0;
        
        ans = dijkstra(0, n - 1, maxTime, cost, time);
        
        return ans == INT_MAX ? -1 : ans;
    }
};