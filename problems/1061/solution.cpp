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
    string smallestEquivalentString(string A, string B, string S) {
        string ans = "";
        disjoint_set ds(26 + 1);
        
        for (int i = 0; i < A.size(); i++) {
            ds.merge(A[i] - 'a', B[i] - 'a');
        }
        
        for (char& ch: S) {
            for (char i = 'a'; i <= 'z'; i++) {
                if (ds.find(ch - 'a') == ds.find(i - 'a')) {
                    ans += i;
                    break;
                }
            }
        }
        
        return ans;
    }
};