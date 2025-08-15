class Solution {
private:
    int dfs(const vector<vector<int>>& g, int node, int parent, int k) {
        if (k < 0) {
            return 0;
        }

        int ans = 1;
        
        for (int next : g[node]) {
            if (next == parent) {
                continue;
            }

            ans += dfs(g, next, node, k - 1);
        }
        
        return ans;
    }

    vector<int> build(const vector<vector<int>>& edges, int k) {
        int n = size(edges) + 1;
        vector<vector<int>> g(n);
        vector<int> ans(n);

        for (const auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        for (int i = 0; i < n; i++) {
            ans[i] = dfs(g, i, -1, k);
        }

        return ans;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = size(edges1) + 1,
            m = size(edges2) + 1;
        vector<int> count1 = build(edges1, k),
            count2 = build(edges2, k - 1),
            ans(n);
        int maxCount2 = *max_element(begin(count2), end(count2));
        
        for (int i = 0; i < n; i++) {
            ans[i] = count1[i] + maxCount2;
        }
        
        return ans;
    }
};