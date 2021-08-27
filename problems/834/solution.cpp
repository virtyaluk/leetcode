typedef unordered_map<int, unordered_set<int>> graph;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n), count(n, 1);
        graph g;
        
        for (const vector<int>& edge: edges) {
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        
        dfs1(g, 0, -1, count, ans);
        dfs2(g, 0, -1, n, count, ans);
        
        return ans;
    }
    
    void dfs1(graph& g, int node, int parent, vector<int>& count, vector<int>& ans) {
        for (const int& next: g[node]) {
            if (next == parent) {
                continue;
            }
            
            dfs1(g, next, node, count, ans);
            
            count[node] += count[next];
            ans[node] += ans[next] + count[next];
        }
    }
    
    void dfs2(graph& g, int node, int parent, int n, vector<int>& count, vector<int>& ans) {
        for (const int& next: g[node]) {
            if (next == parent) {
                continue;
            }
            
            ans[next] = ans[node] - 2 * count[next] + n;
            dfs2(g, next, node, n, count, ans);
        }
    }
};