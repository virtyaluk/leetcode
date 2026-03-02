class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);
        vector<int> d(n, INT_MAX);
        vector<bool> v(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        d[0] = 0;
        q.emplace(0, 0);

        for (const vector<int>& e: edges) {
            int x = e[0],
                y = e[1],
                w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, 2 * w);
        }

        while (not empty(q)) {
            int x = q.top().second;
            q.pop();

            if (x == n - 1) {
                return d[x];
            }

            if (v[x]) {
                continue;
            }

            v[x] = true;

            for (auto &[y, w]: g[x]) {
                if (d[x] + w < d[y]) {
                    d[y] = d[x] + w;
                    q.emplace(d[y], y);
                }
            }
        }
        
        return -1;
    }
};