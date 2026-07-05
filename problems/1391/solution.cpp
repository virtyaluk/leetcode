static constexpr int MAX_N = 300 * 300 + 5;
static constexpr int patterns[7] = {0, 0b1010, 0b0101, 0b1100, 0b0110, 0b1001, 0b0011};
static constexpr int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

class Solution {
public:
    struct DS {
        int f[MAX_N];

        DS() {
            iota(begin(f), end(f), 0);
        }

        int find(int x) {
            return x == f[x] ? x : f[x] = find(f[x]);
        }

        void merge(int x, int y) {
            f[find(x)] = find(y);
        }
    } ds;

    bool hasValidPath(vector<vector<int>>& g) {
        int m = size(g),
            n = size(g.front());
        auto getId = [&](int x, int y) -> int {
            return x * n + y;
        };
        auto handler = [&](int x, int y) {
            int pat = patterns[g[x][y]];

            for (int i = 0; i < 4; i++) {
                if (pat & (1 << i)) {
                    int sx = x + dirs[i][0],
                        sy = y + dirs[i][1];
                    
                    if (sx >= 0 and sx < m and sy >= 0 and sy < n and (patterns[g[sx][sy]] & (1 << ((i + 2) % 4)))) {
                        ds.merge(getId(x, y), getId(sx, sy));
                    }
                }
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                handler(i, j);
            }
        }

        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }
};