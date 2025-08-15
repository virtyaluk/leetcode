class Solution {
private:
    int dfs(const vector<vector<int>>& g, vector<int>& color, int node, int parent, int depth) {
        int ans = 1 - depth % 2;
        color[node] = depth % 2;
        
        for (int child : g[node]) {
            if (child == parent) {
                continue;
            }
            
            ans += dfs(g, color, child, node, depth + 1);
        }
        
        return ans;
    }

    vector<int> build(const vector<vector<int>>& edges, vector<int>& color) {
        int n = size(edges) + 1;
        vector<vector<int>> g(n);
        
        for (const auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        int ans = dfs(g, color, 0, -1, 0);
        
        return {ans, n - ans};
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = size(edges1) + 1,
            m = size(edges2) + 1;
        vector<int> color1(n),
            color2(m),
            count1 = build(edges1, color1),
            count2 = build(edges2, color2),
            ans(size(edges1) + 1);

        for (int i = 0; i < n; i++) {
            ans[i] = count1[color1[i]] + max(count2[0], count2[1]);
        }

        return ans;
    }
};