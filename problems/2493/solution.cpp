class Solution {
private:
    bool isBipartite(unordered_map<int, unordered_set<int>>& g, vector<int>& colors, int node) {
        for (const int& next: g[node]) {
            if (colors[next] == colors[node]) {
                return false;
            }

            if (colors[next] != -1) {
                continue;
            }

            colors[next] = (colors[node] + 1) % 2;

            if (not isBipartite(g, colors, next)) {
                return false;
            }
        }

        return true;
    }

    int getLongestShortestPath(unordered_map<int, unordered_set<int>>& g, int n, int node) {
        int ans = 0;
        queue<int> q;
        vector<bool> visited(n);

        q.push(node);
        visited[node] = true;

        while (not empty(q)) {
            for (int i = 0, qSize = size(q); i < qSize; i++) {
                int cur = q.front();
                q.pop();

                for (const int& next: g[cur]) {
                    if (visited[next]) {
                        continue;
                    }

                    visited[next] = true;
                    q.push(next);
                }
            }

            ans++;
        }

        return ans;
    }

    int getNumOfGroups(unordered_map<int, unordered_set<int>>& g, vector<int>& dist, vector<bool>& visited, int node) {
        int ans = dist[node];
        visited[node] = true;

        for (const int& next: g[node]) {
            if (visited[next]) {
                continue;
            }

            ans = max(ans, getNumOfGroups(g, dist, visited, next));
        }

        return ans;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        int ans = 0;
        unordered_map<int, unordered_set<int>> g;
        vector<int> colors(n, -1),
            dist(n);
        vector<bool> visited(n);

        for (const vector<int>& e: edges) {
            g[e.front() - 1].insert(e.back() - 1);
            g[e.back() - 1].insert(e.front() - 1);
        }

        for (int i = 0; i < n; i++) {
            if (colors[i] != -1) {
                continue;
            }

            colors[i] = 0;

            if (not isBipartite(g, colors, i)) {
                return -1;
            }
        }

        for (int i = 0; i < n; i++) {
            dist[i] = getLongestShortestPath(g, n, i);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }

            ans += getNumOfGroups(g, dist, visited, i);
        }

        return ans;
    }
};