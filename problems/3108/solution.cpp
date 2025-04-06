class Solution {
private:
    int dfs(const vector<vector<pair<int, int>>>& g, vector<int>& components, vector<bool>& visited, int node, int compId) {
        int ans = INT_MAX;
        components[node] = compId;
        visited[node] = true;

        for (auto& [next, w]: g[node]) {
            ans &= w;

            if (not visited[next]) {
                ans &= dfs(g, components, visited, next, compId);
            }
        }

        return ans;
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        vector<vector<pair<int, int>>> g(n);
        vector<int> components(n),
            cost;
        vector<bool> visited(n);
        int compId = 0;

        for (const vector<int>& e: edges) {
            g[e.front()].push_back({e[1], e.back()});
            g[e[1]].push_back({e.front(), e.back()});
        }

        for (int i = 0; i < n; i++) {
            if (not visited[i]) {
                cost.push_back(dfs(g, components, visited, i, compId++));
            }
        }

        for (const vector<int>& q: query) {
            int start = q.front(),
                end = q.back();
            
            if (components[start] == components[end]) {
                ans.push_back(cost[components[start]]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};