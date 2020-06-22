class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<bool> visited(n);
        unordered_map<int, unordered_set<int>> graph;
        
        for (const vector<int>& e: edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (not visited[i]) {
                ans++;
                dfs(graph, visited, i);
            }
        }
        
        return ans;
    }
    
    void dfs(unordered_map<int, unordered_set<int>>& g, vector<bool>& visited, int node) {
        visited[node] = true;
        
        for (const int& next: g[node]) {
            if (not visited[next]) {
                dfs(g, visited, next);
            }
        }
    }
};