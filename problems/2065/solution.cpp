class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int ans = 0,
            n = size(values);
        vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
        vector<int> visited(n, 0),
            scores(n, 0);
        function<void(int, int, int)> dfs = [&](int node, int gain, int tr) -> void {
            if (visited[node] == 0) {
                gain += scores[node];
            }

            visited[node]++;

            if (node == 0) {
                ans = max(ans, gain);
            }

            for (auto next: g[node]) {
                if (next.second <= tr) {
                    dfs(next.first, gain, tr - next.second);
                }
            }

            visited[node]--;

            if (visited[node] == 0) {
                gain -= scores[node];
            }
        };

        for (const vector<int>& e: edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }

        for (int i = 0; i < n; i++) {
            scores[i] = values[i];
        }

        dfs(0, 0, maxTime);

        return ans;
    }
};