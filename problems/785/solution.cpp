class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = size(graph);
        vector<int> colors(n);
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (colors[i] != 0) {
                continue;
            }
            
            q.push(i);
            colors[i] = 1;
            
            while (not q.empty()) {
                int node = q.front();
                q.pop();
                
                for (const int& next: graph[node]) {
                    if (colors[next] == colors[node]) {
                        return false;
                    }
                    
                    if (colors[next] == 0) {
                        colors[next] = ~colors[node];
                        q.push(next);
                    }
                }
            }
        }
        
        return true;
    }
};