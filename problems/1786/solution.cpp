const int MOD = 1e9 + 7;

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> g;
        
        for (const vector<int>& edge: edges) {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> dist = dijkstra(g, n),
            dp(n + 1, -1);
        
        return dfs(dp, g, dist, 1, n);
    }
    
    vector<int> dijkstra(unordered_map<int, vector<pair<int, int>>>& g, int n) {
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        dist[n] = 0;
        pq.push({0, n});
        
        while (not empty(pq)) {
            auto [prevDist, u] = pq.top();
            pq.pop();
            
            if (prevDist != dist[u]) {
                continue;
            }
            
            for (auto [v, w]: g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
    
    int dfs(
        vector<int>& dp,
        unordered_map<int, vector<pair<int, int>>>& g,
        vector<int>& dist,
        int start,
        int end
    ) {
        if (start == end) {
            return 1;
        }
        
        if (dp[start] != -1) {
            return dp[start];
        }
        
        int ans = 0;
        
        for (auto [v, ignore]: g[start]) {
            if (dist[start] > dist[v]) {
                ans = (ans + dfs(dp, g, dist, v, end)) % MOD;
            }
        }
        
        return dp[start] = ans;
    }
};