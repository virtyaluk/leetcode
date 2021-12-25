class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int ans = 0;
        unordered_map<int, unordered_set<int>> graph;
        
        for (const vector<int>& edge: edges) {
            int u = edge[0], v = edge[1];
            
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        dfs(graph, 0, -1, ans);
        
        return ans;
    }
    
    int dfs(unordered_map<int, unordered_set<int>>& g, int node, int parent, int& ans) {
        if (not g.count(node)) {
            return 0;
        }
        
        int firstMax = 0, secondMax = 0;
        
        for (const int& next: g[node]) {
            if (next == parent) {
                continue;
            }
            
            int depth = dfs(g, next, node, ans);
            
            if (depth > firstMax) {
                secondMax = firstMax;
                firstMax = depth;
            } else if (depth > secondMax) {
                secondMax = depth;
            }
        }
        
        ans = max(ans, firstMax + secondMax);
        
        return 1 + firstMax;
    }
};