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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = size(edges);
        disjoint_set ds(n + 1);
        
        for (const vector<int>& e: edges) {
            if (not ds.merge(e[0], e[1])) {
                return e;
            }
        }
        
        return {};
    }
};