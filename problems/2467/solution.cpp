class Solution {
private:
    int dfs(unordered_map<int, unordered_set<int>>& g, vector<int>& dist, vector<int>& amount, int node, int parent, int time, int bob, int& n) {
        int profit = 0,
            maxDepth = INT_MIN;

        if (node == bob) {
            dist[node] = 0;
        } else {
            dist[node] = n;
        }

        for (const int& next : g[node]) {
            if (next != parent) {
                maxDepth = max(maxDepth, dfs(g, dist, amount, next, node, time + 1, bob, n));
                dist[node] = min(dist[node], dist[next] + 1);
            }
        }
        
        if (dist[node] > time) {
            profit += amount[node];
        } else if (dist[node] == time) {
            profit += amount[node] / 2;
        }

        return maxDepth == INT_MIN ? profit : profit + maxDepth;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = size(amount);
        unordered_map<int, unordered_set<int>> g;
        vector<int> dist(n);

        for (const vector<int>& e : edges) {
            g[e.front()].insert(e.back());
            g[e.back()].insert(e.front());
        }
        
        return dfs(g, dist, amount, 0, 0, 0, bob, n);
    }
};