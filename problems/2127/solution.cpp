class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int ans1 = 0,
            ans2 = 0,
            curDist = 1,
            n = size(favorite);
        unordered_map<int, unordered_set<int>> g;
        vector<bool> visited(n),
            curPath(n);
        vector<int> dist(n);
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            curPath[node] = true;
            dist[node] = curDist++;

            int next = favorite[node];

            if (not visited[next]) {
                dfs(next);
            }

            if (curPath[next]) {
                ans1 = max(ans1, dist[node] - dist[next] + 1);
            }

            curPath[node] = false;
        };
        function<int(int)> dfs2 = [&](int node) {
            int ans = 1;

            for (const int& next: g[node]) {
                if (next != favorite[node]) {
                    ans = max(ans, dfs2(next) + 1);
                }
            }

            return ans;
        };

        for (int i = 0; i < n; i++) {
            g[favorite[i]].insert(i);
        }

        for (int i = 0; i < n; i++) {
            if (not visited[i]) {
                dfs(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == favorite[favorite[i]] and i < favorite[i]) {
                ans2 += dfs2(i) + dfs2(favorite[i]);
            }
        }

        return max(ans1, ans2);
    }
};