const int MOD = 1e9 + 7;
const int N = 100010;
int p2[N];
auto init = [] {
    p2[0] = 1;

    for (int i = 1; i < N; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }

    return 0;
}();

class LCA {
private:
    int n, m;
    vector<int> d;
    vector<vector<int>> e, f;

public:
    LCA(const vector<vector<int>>& edges, const int root = 1) {
        n = size(edges) + 1;
        m = (log(n) / log(2)) + 1;
        e.resize(n + 1);
        d.resize(n + 1);
        f.resize(n + 1, vector<int>(m, 0));

        for (auto& ee: edges) {
            int u = ee[0],
                v = ee[1];
            e[u].push_back(v);
            e[v].push_back(u);
        }

        dfs(root, 0);

        for (int i = 1; i < m; i++) {
            for (int x = 1; x <= n; x++) {
                f[x][i] = f[f[x][i - 1]][i - 1];
            }
        }
    }

    void dfs(int x, int fa) {
        f[x][0] = fa;

        for (auto& y: e[x]) {
            if (y == fa) {
                continue;
            }

            d[y] = d[x] + 1;
            dfs(y, x);
        }
    }

    int lca(int x, int y) {
        if (d[x] > d[y]) {
            swap(x, y);
        }

        for (int i = m - 1; i >= 0; i--) {
            if (d[x] <= d[f[y][i]]) {
                y = f[y][i];
            }
        }

        if (x == y) {
            return x;
        }

        for (int i = m - 1; i >= 0; i--) {
            if (f[y][i] != f[x][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }

        return f[x][0];
    }

    int dis(int x, int y) {
        return d[x] + d[y] - d[lca(x, y)] * 2;
    }
};

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LCA lca(edges, 1);
        int m = size(queries);
        vector<int> ans(m);

        for (int i = 0; i < m; i++) {
            int x = queries[i][0],
                y = queries[i][1];
            
            if (x != y) {
                ans[i] = p2[lca.dis(x, y) - 1];
            }
        }

        return ans;
    }
};