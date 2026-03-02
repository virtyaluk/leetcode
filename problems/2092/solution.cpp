class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        iota(begin(parent), end(parent), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x),
            py = find(y);
        
        if (px != py) {
            if (rank[px] > rank[py]) {
                parent[py] = px;
            } else if (rank[px] < rank[py]) {
                parent[px] = py;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    void reset(int x) {
        parent[x] = x;
        rank[x] = 0;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> ans;
        map<int, vector<pair<int, int>>> stm;
        UnionFind g(n);

        g.unite(firstPerson, 0);

        sort(begin(meetings), end(meetings), [](auto& lhs, auto& rhs) {
            return lhs[2] < rhs[2];
        });

        for (auto& m: meetings) {
            int x = m[0],
                y = m[1],
                t = m[2];
            stm[t].emplace_back(x, y);
        }

        for (auto& [_, ms]: stm) {
            for (auto& [x, y]: ms) {
                g.unite(x, y);
            }

            for (auto& [x, y]: ms) {
                if (not g.connected(x, 0)) {
                    g.reset(x);
                    g.reset(y);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (g.connected(i, 0)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};