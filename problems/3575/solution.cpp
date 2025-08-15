class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    vector<vector<int>> tree;
    vector<int> vals;
    vector<int> dp;

    int digitMask(int val) {
        int mask = 0;
        while (val > 0) {
            int d = val % 10;
            if ((mask >> d) & 1)
                return -1; // duplicate digit
            mask |= (1 << d);
            val /= 10;
        }
        return mask;
    }

    unordered_map<int, int> dfs(int u, const vector<int>& digitMasks) {
        unordered_map<int, int> cur;
        if (digitMasks[u] != -1)
            cur[digitMasks[u]] = vals[u];

        for (int v : tree[u]) {
            auto child = dfs(v, digitMasks);
            unordered_map<int, int> next = cur;

            for (const auto& [mask1, sum1] : cur) {
                for (const auto& [mask2, sum2] : child) {
                    if ((mask1 & mask2) == 0) {
                        next[mask1 | mask2] = max(next[mask1 | mask2], sum1 + sum2);
                    }
                }
            }

            for (const auto& [mask2, sum2] : child) {
                next[mask2] = max(next[mask2], sum2);
            }

            cur = move(next);
        }

        int best = 0;
        for (const auto& [_, val] : cur)
            best = max(best, val);
        dp[u] = best;
        return cur;
    }

    int goodSubtreeSum(vector<int>& _vals, vector<int>& par) {
        vals = _vals;
        int n = vals.size();
        tree.assign(n, {});
        dp.assign(n, 0);

        for (int i = 1; i < n; ++i)
            tree[par[i]].push_back(i);

        vector<int> digitMasks(n);
        for (int i = 0; i < n; ++i)
            digitMasks[i] = digitMask(vals[i]);

        dfs(0, digitMasks);
        ll total = 0;
        for (int x : dp) total = (total + x) % MOD;
        return (int)total;
    }
};
