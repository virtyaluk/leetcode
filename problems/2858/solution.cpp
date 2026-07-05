class Solution {
private:
    int dfs(vector<vector<pair<int, int>>>& g, int idx, int p) {
        int ans = 0;

        for (auto &e: g[idx]) {
            if (e.first != p) {
                if (e.second == 0) {
                    ans += dfs(g, e.first, idx);
                } else {
                    ans += 1 + dfs(g, e.first, idx);
                }
            }
        }

        return ans;
    }
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);
        queue<int> q;
        vector<bool> visited(n);
        vector<int> ans(n);

        for (auto &e: edges) {
            g[e.front()].push_back({e.back(), 0});
            g[e.back()].push_back({e.front(), 1});
        }

        q.push(0);
        ans.front() = dfs(g, 0, -1);
        visited[0] = true;

        while (not empty(q)) {
            int p = q.front();
            q.pop();

            for (auto& neighbor : g[p]) {
                int child = neighbor.first;
                int type = neighbor.second;

                if (!visited[child]) {
                    visited[child] = 1;
    
                    if (type == 0) {
                        ans[child] = ans[p] + 1;
                    } else {
                        ans[child] = ans[p] - 1;
                    }

                    q.push(child);
                }
            }
        }

        return ans;
    }
};