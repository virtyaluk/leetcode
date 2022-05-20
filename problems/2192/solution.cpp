class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        unordered_map<int, unordered_set<int>> g;
        
        for (const vector<int>& edge: edges) {
            g[edge[0]].insert(edge[1]);
        }
        
        for (int i = 0; i < n; i++) {
            dfs(g, ans, i, i);
        }
        
        return ans;
    }
    
    void dfs(unordered_map<int, unordered_set<int>>& g, vector<vector<int>>& ans, int i, int anc) {
        for (const int& j: g[i]) {
            if (empty(ans[j]) or ans[j].back() != anc) {
                ans[j].push_back(anc);
                dfs(g, ans, j, anc);
            }
        }
    }
};