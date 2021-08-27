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
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> g(26);
        vector<int> colors(26);
        queue<int> q;
        int color = 0;
        
        for (const string& eq: equations) {
            if (eq[1] == '=') {
                int a = eq[0] - 'a', b = eq[3] - 'a';
                
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (colors[i] == 0) {
                color++;
                q.push(i);
                
                while (not q.empty()) {
                    const int a = q.front();
                    q.pop();
                    
                    colors[a] = color;
                    
                    for (const int& b: g[a]) {
                        if (colors[b] == 0) {
                            q.push(b);
                        }
                    }
                }
            }
        }
        
        for (const string& eq: equations) {
            if (eq[1] == '!') {
                int a = eq[0] - 'a', b = eq[3] - 'a';
                
                if (a == b) {
                    return false;
                }
                
                if (colors[a] == colors[b]) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool equationsPossible1(vector<string>& equations) {
        vector<ll> id(27), rank(27);
        make_set(id, rank, 26);
        
        for (const string& eq: equations) {
            if (eq[1] == '=') {
                merge_set(id, rank, eq[0] - 'a', eq[3] - 'a');
            }
        }
        
        for (const string& eq: equations) {
            if (eq[1] == '!' && find_set(id, eq[0] - 'a') == find_set(id, eq[3] - 'a')) {
                return false;
            }
        }
        
        return true;
    }
};