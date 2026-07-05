class UF {
private:
    vector<int> parent, size;
    int n, setCount;

public:
    UF(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(begin(parent), end(parent), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }

        parent[y] = x;
        size[x] += size[y];
        --setCount;
    }

    bool findun(int x, int y) {
        int px = find(x),
            py = find(y);
        
        if (px != py) {
            unite(px, py);

            return true;
        }

        return false;
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& g) {
        int m = size(g),
            n = size(g.front());
        UF uf(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 and g[i][j] == g[i - 1][j]) {
                    if (not uf.findun(i * n + j, (i - 1) * n + j)) {
                        return true;
                    }
                }

                if (j > 0 and g[i][j] == g[i][j - 1]) {
                    if (not uf.findun(i * n + j, i * n + j - 1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};