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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        int ans = 0;
        disjoint_set ds(n + 1);
        
        for (int i = 1; i <= n; i++) {
            pipes.push_back({0, i, wells[i - 1]});
        }
        
        sort(pipes.begin(), pipes.end(), [](auto& lhs, auto& rhs) {
            return lhs[2] < rhs[2];
        });
        
        for (auto& pipe: pipes) {
            if (ds.find(pipe[0]) != ds.find(pipe[1])) {
                ans += pipe[2];
                ds.merge(pipe[0], pipe[1]);
            }
        } 
        
        return ans;
    }
};