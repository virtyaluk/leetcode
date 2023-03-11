class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<bool> visited(n);
        unordered_map<int, unordered_set<int>> g;
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        for (const vector<int>& edge: edges) {
            int u = edge[0], v = edge[1];
            
            g[u].insert(v);
            g[v].insert(u);
        }
        
        while (not empty(q)) {
            int node = q.front();
            q.pop();
            
            if (node == end) {
                return true;
            }
            
            for (int next: g[node]) {
                if (visited[next]) {
                    continue;
                }
                
                visited[next] = true;
                q.push(next);
            }
        }
        
        return false;
    }
};