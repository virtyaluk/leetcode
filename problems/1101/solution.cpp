#define ll long long

void make_set(vector<ll> &id, vector<ll> &rank, ll n) {
    for(ll i=1; i<=n; i++) {
        id[i] = i;
        rank[i] = 1;
    }
}

ll find_set(vector<ll> &id, ll p) {
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

bool merge_set(vector<ll> &id, vector<ll> &rank, ll x, ll y) {
    x = find_set(id, x);
    y = find_set(id, y);
    
    if (x == y) {
        return false;
    }
    
    if(rank[x] > rank[y])
        id[y] = x;
    else
        id[x] = y;
    if(rank[x] == rank[y])
        rank[y] += 1;
    
    return true;
}

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<ll> id(N + 1), rank(N + 1);
        
        make_set(id, rank, N);
        sort(logs.begin(), logs.end(), [](vector<int> &lhs, vector<int> &rhs) {
           return lhs[0] < rhs[0]; 
        });
        
        for (int i = 0; i < logs.size(); i++) {
            if (merge_set(id, rank, logs[i][1], logs[i][2])) {
                N--;
            }
            
            if (N == 1) {
                return logs[i][0];
            }
        }
        
        return -1;
    }
};