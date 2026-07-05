class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = size(online),
            lo = INT_MAX,
            hi = 0;
        vector<vector<pair<int, int>>> g(n);
        auto check = [&](int mid) -> int {
            vector<long long> memo(n, -1);
            auto dfs = [&](this auto&& dfs, int u) -> long long {
                if (u == n - 1) {
                    return 0;
                }

                if (memo[u] != -1) {
                    return memo[u];
                }

                long long ans = LLONG_MAX / 2;

                for (auto& [v, w]: g[u]) {
                    if (w >= mid) {
                        ans = min(ans, dfs(v) + w);
                    }
                }

                memo[u] = ans;

                return memo[u];
            };

            return dfs(0) <= k;
        };

        for (auto& e: edges) {
            int u = e[0],
                v = e[1],
                w = e[2];

            if (not online[u] or not online[v]) {
                continue;
            }

            g[u].push_back({v, w});
            lo = min(lo, w);
            hi = max(hi, w);
        }

        if (not check(lo)) {
            return -1;
        }

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;

            if (check(mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return hi;
    }
};