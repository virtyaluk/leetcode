class Solution {
private:
    int dist(int n, int source, int dest, const vector<vector<pair<int, int>>>& g) {
        vector<int> md(n, 2e9);
        vector<bool> visited(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        md[source] = 0;
        pq.push({0, source});
        
        while (not empty(pq)) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > md[u]) {
                continue;
            }
            
            for (const auto &[v, w]: g[u]) {
                if (d + w < md[v]) {
                    md[v] = d + w;
                    pq.push({md[v], v});
                }
            }
        }
        
        return md[dest];
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> g(n);
        
        for (const vector<int>& e: edges) {
            if (e[2] != -1) {
                g[e[0]].push_back({e[1], e[2]});
                g[e[1]].push_back({e[0], e[2]});
            }
        }
        
        int curShortDist = dist(n, source, destination, g);
        bool matchesTarget = curShortDist == target;
        
        if (curShortDist < target) {
            return {};
        }
        
        for (vector<int>& e: edges) {
            if (e[2] != -1) {
                continue;
            }
            
            e[2] = matchesTarget ? 2e9 : 1;
            
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
            
            if (not matchesTarget) {
                int nextDist = dist(n, source, destination, g);
                
                if (nextDist <= target) {
                    matchesTarget = true;
                    e[2] += target - nextDist;
                }
            }
        }
        
        if (matchesTarget) {
            return edges;
        }
        
        return {};
    }
};