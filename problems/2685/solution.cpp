class Solution {
private:
    void dfs(unordered_map<int, unordered_set<int>>& g, vector<bool>& visited, pair<int, int>& nae, int node) {
        nae.first++;
        nae.second += size(g[node]);
        visited[node] = true;

        for (const int& next: g[node]) {
            if (not visited[next]) {
                dfs(g, visited, nae, next);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        unordered_map<int, unordered_set<int>> g;
        vector<bool> visited(n);

        for (const vector<int>& e: edges) {
            g[e.front()].insert(e.back());
            g[e.back()].insert(e.front());
        }

        for (int i = 0; i < n; i++) {
            if (not visited[i]) {
                pair<int, int> nodesAndEdges = {0, 0};

                dfs(g, visited, nodesAndEdges, i);
                ans += nodesAndEdges.second == nodesAndEdges.first * (nodesAndEdges.first - 1);
            }
        }

        return ans;
    }
};