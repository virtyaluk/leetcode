const int MOD = 1e9 + 7;

class Solution {
public:
    int colorTheGrid(int m, int n) {
        unordered_map<int, vector<int>> um,
            g;
        int ans = 0,
            maskEnd = pow(3, m);
        vector<int> f(maskEnd);

        for (int mask = 0; mask < maskEnd; mask++) {
            vector<int> color;
            int mm = mask;
            bool check = true;

            for (int i = 0; i < m; i++) {
                color.push_back(mm % 3);
                mm /= 3;
            }

            for (int i = 0; i < m - 1; i++) {
                if (color[i] == color[i + 1]) {
                    check = false;
                    break;
                }
            }

            if (check) {
                um[mask] = move(color);
            }
        }

        for (const auto& [m1, c1]: um) {
            for (const auto& [m2, c2]: um) {
                bool check = true;

                for (int i = 0; i < m; i++) {
                    if (c1[i] == c2[i]) {
                        check = false;
                        break;
                    }
                }

                if (check) {
                    g[m1].push_back(m2);
                }
            }
        }

        for (const auto& [mask, _]: um) {
            f[mask] = 1;
        }

        for (int i = 1; i < n; i++) {
            vector<int> vi(maskEnd);

            for (const auto& [mask2, _]: um) {
                for (int mask1: g[mask2]) {
                    vi[mask2] += f[mask1];

                    if (vi[mask2] >= MOD) {
                        vi[mask2] -= MOD;
                    }
                }
            }

            f = move(vi);
        }

        for (int num: f) {
            ans += num;

            if (ans >= MOD) {
                ans -= MOD;
            }
        }

        return ans;
    }
};