class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = -1, ansMinCities = INT_MAX;
        unordered_map<int, vector<pair<int, int>>> g;
        
        for (const vector<int>& edge: edges) {
            int u = edge[0],
                v = edge[1],
                weight = edge[2];
            
            g[u].push_back({v, weight});
            g[v].push_back({u, weight});
        }
        
        for (int i = 0; i < n; i++) {
            int reachableCities = dijkstra(g, i, distanceThreshold);
            
            if (reachableCities <= ansMinCities) {
                ansMinCities = reachableCities;
                ans = i;
            }
        }
        
        return ans;
    }
    
    int dijkstra(unordered_map<int, vector<pair<int, int>>>& g, int u, int maxDist) {
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(size(g) + 1, INT_MAX);
        
        pq.push({0, u});
        dist[u] = 0;
        
        while (not empty(pq)) {
            auto [nw, node] = pq.top();
            pq.pop();
            
            for (auto [v, w]: g[node]) {
                if (dist[v] > dist[node] + w) {
                    dist[v] = dist[node] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        for (int i = 0; i < size(dist); i++) {
            if (i != u and dist[i] <= maxDist) {
                ans++;
            }
        }
        
        return ans;
    }
};