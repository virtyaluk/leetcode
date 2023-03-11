class DSU {
public:
    vector<int> parent, rank;
    int size;
    DSU (int _n) {
        parent.resize(_n, -1);
        rank.resize(_n, 1);
        size = _n;
        for (int i = 0; i < _n; ++i) {
            parent[i] = i;
        }
    }
    
    int getParent(int u) {
        if (parent[u] != u) parent[u] = getParent(parent[u]);
        return parent[u];
    }
    
    void merge(int u, int v) {
        int x = getParent(u);
        int y = getParent(v);
        //since both the nodes belong in the 
        //same group
        //there is no point merging their group
        if (x == y) return ;
        
        //make sure that the rank of x is always smaller than y
        if (rank[x] > rank[y]) swap(x, y);
        
        //y will always be the parent
        rank[y] += rank[x];
        parent[x] = y;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        long long int ans = 0,
            n = size(vals);
        unordered_map<int, vector<int>> g;
        map<int, vector<int>> valuesToNodes;
        unordered_set<int> activated;
        unordered_map<int, int> parentCount;
        DSU dsu(n + 1);
        
        for (const vector<int>& edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        for (int i = 0; i < n; i++) {
            valuesToNodes[vals[i]].push_back(i);
        }
        
        for (auto &[val, nodes]: valuesToNodes) {
            int components = 0;
            
            parentCount.clear();
            activated.insert(begin(nodes), end(nodes));
            
            for (const int& node: nodes) {
                for (int &next: g[node]) {
                    if (activated.count(next)) {
                        dsu.merge(node, next);
                    }
                }
            }
            
            for (const int& node: nodes) {
                parentCount[dsu.getParent(node)]++;
            }
            
            for (auto &[node, cnt]: parentCount) {
                components += (cnt * (cnt - 1) / 2);
            }
            
            ans += components;
        }
        
        return ans + n;
    }
};