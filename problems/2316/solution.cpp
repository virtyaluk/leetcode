class Solution {
private:
    int bfs(int node, vector<vector<int>>& g, vector<bool>& visited) {
        int ans = 1;
        queue<int> q;
        
        q.push(node);
        visited[node] = true;
        
        while (not empty(q)) {
            node = q.front();
            q.pop();
            
            for (int next: g[node]) {
                if (not visited[next]) {
                    visited[next] = true;
                    ans++;
                    q.push(next);
                }
            }
        }
        
        return ans;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0,
            componentSize = 0,
            remaining = n;
        vector<vector<int>> g(n);
        vector<bool> visited(n);
        
        for (const vector<int>& e: edges) {
            g[e.front()].push_back(e.back());
            g[e.back()].push_back(e.front());
        }
        
        for (int i = 0; i < n; i++) {
            if (not visited[i]) {
                componentSize = bfs(i, g, visited);
                ans += componentSize * (remaining - componentSize);
                remaining -= componentSize;
            }
        }
        
        return ans;
    }
};