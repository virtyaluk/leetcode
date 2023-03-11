class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> g(n + 1);
        vector<bool> visited(n +1);
        queue<int> q;
        
        visited[1] = true;
        q.push(1);
        
        for (const vector<int>& v: roads) {
            g[v[0]].push_back({v[1], v[2]});
            g[v[1]].push_back({v[0], v[2]});
        }
        
        while (not empty(q)) {
            int node = q.front();
            q.pop();
            
            for (auto& next: g[node]) {
                ans = min(ans, next.second);
                
                if (not visited[next.first]) {
                    visited[next.first] = true;
                    q.push(next.first);
                }
            }
        }
        
        return ans;
    }
};