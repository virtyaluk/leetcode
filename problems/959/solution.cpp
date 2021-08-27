#define ll long long

class disjoint_set {
private:
    vector<ll> id, rank;
    ll size;

public:
    disjoint_set(ll n) {
        size = n;
        
        id.resize(n);
        rank.resize(n, 1);
        iota(id.begin(), id.end(), 0);
    }
    
    ll find(ll p) {
        ll root = p;
        //find the root
        while(root != id[root]) {
            root = id[root];
        }

        //perform path compression
        while(p != root) {
            ll newp = id[p];
            id[p] = root;
            p = newp;
        }

        return root;
    }
    
    bool merge(ll x, ll y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return false;
        }

        if (rank[x] > rank[y]) {
            id[y] = x;
        } else {
            id[x] = y;
        }

        if (rank[x] == rank[y]) {
            rank[y] += 1;
        }

        return true;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size(), ans = 0;
        disjoint_set ds(n * n * 4);
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int root = 4 * (r * n + c);
                char ch = grid[r][c];
                
                if (ch != '/') {
                    ds.merge(root, root + 1);
                    ds.merge(root + 2, root + 3);
                }
                
                if (ch != '\\') {
                    ds.merge(root, root + 3);
                    ds.merge(root + 1, root + 2);
                }
                
                if (r - 1 >= 0) {
                    ds.merge(root, (root - n * 4) + 2);
                }
                
                if (r + 1 < n) {
                    ds.merge(root + 2, (root + n * 4));
                }
                
                if (c - 1 >= 0) {
                    ds.merge(root + 3, (root - 4) + 1);
                }
                
                if (c + 1 < n) {
                    ds.merge(root + 1, (root + 4) + 3);
                }
            }
        }
        
        for (int i = 0; i < n * n * 4; i++) {
            if (ds.find(i) == i) {
                ans++;
            }
        }
        
        return ans;
    }
};