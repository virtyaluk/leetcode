const int MOD = 1e9 + 7;
using ll = long long;

class Solution {
private:
    int pow(ll x, ll y) {
        ll ans = 1;

        for (; y; y >>= 1) {
            if (y & 1) {
                ans = ans *x % MOD;
            }

            x = x * x % MOD;
        }

        return ans;
    }
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0,
            n = size(nums),
            t = sqrt(n);
        vector<vector<vector<int>>> groups(t);
        vector<ll> dif(n + t);

        for (auto &q: queries) {
            int l = q[0],
                r = q[1],
                k = q[2],
                v = q[3];
            
            if (k < t) {
                groups[k].push_back({l, r, v});
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = 1ll * nums[i] * v % MOD;
                }
            }
        }

        for (int k = 1; k < t; k++) {
            if (empty(groups[k])) {
                continue;
            }

            fill(begin(dif), end(dif), 1);

            for (auto &q: groups[k]) {
                int l = q[0],
                    r = q[1],
                    v = q[2];
                dif[l] = dif[l] * v % MOD;
                int rr = ((r - l) / k + 1) * k + l;
                dif[rr] = dif[rr] * pow(v, MOD - 2) % MOD;
            }

            for (int i = k; i < n; i++) {
                dif[i] = dif[i] * dif[i - k] % MOD;
            }

            for (int i = 0; i < n; i++) {
                nums[i] = 1ll * nums[i] * dif[i] % MOD;
            }
        }

        for (int i = 0; i < n; i++) {
            ans = ans ^ nums[i];
        }

        return ans;
    }
};