class Solution {
private:
    int ans = -1;
    
    void dfs(const vector<int>& edges, vector<bool>& visited, unordered_map<int, int>& dist, int node) {
        visited[node] = true;
        int next = edges[node];
        
        if (next != -1 and not visited[next]) {
            dist[next] = dist[node] + 1;
            dfs(edges, visited, dist, next);
        } else if (next != -1 and dist.count(next)) {
            ans = max(ans, dist[node] - dist[next] + 1);
        }
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = size(edges);
        vector<bool> visited(n);
        
        for (int i = 0; i < n; i++) {
            if (not visited[i]) {
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(edges, visited, dist, i);
            }
        }
        
        return ans;
    }
};