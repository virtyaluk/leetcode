class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (size(connections) < n - 1) {
            return -1;
        }
        
        int ans = 0;
        vector<vector<int>> g(n);
        vector<bool> visited(n);
        
        for (const vector<int>& con: connections) {
            g[con[0]].push_back(con[1]);
            g[con[1]].push_back(con[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (not visited[i]) {
                dfs(g, visited, i);
                ans++;
            }
        }
        
        return ans - 1;
    }
    
    void dfs(vector<vector<int>>& g, vector<bool>& visited, int node) {
        visited[node] = true;
        
        for (const int& next: g[node]) {
            if (not visited[next]) {
                dfs(g, visited, next);
            }
        }
    }
};