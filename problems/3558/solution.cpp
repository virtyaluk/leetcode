const int MOD = 1e9 + 7;

class Solution {
private:
    int qpow(int x, int y) {
        int ans = 1;

        for (; y; y >>= 1) {
            if (y & 1) {
                ans = 1ll * ans * x % MOD;
            }

            x = 1ll * x * x % MOD;
        }

        return ans;
    }

    int dfs(vector<vector<int>>& g, int x, int f) {
        int ans = 0;

        for (auto& y: g[x]) {
            if (y == f) {
                continue;
            }

            ans = max(ans, dfs(g, y, x) + 1);
        }

        return ans;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = size(edges) + 1;
        vector<vector<int>> g(n + 1);

        for (auto& e: edges) {
            int u = e[0],
                v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        return qpow(2, dfs(g, 1, 0) - 1);
    }
};