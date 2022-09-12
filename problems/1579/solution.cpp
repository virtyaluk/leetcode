class UnionFind {
private:
    vector<int> parent;
    int count;

public:
    UnionFind(int n) {
        count = n;
        
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
        }
    }
    
    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        
        return parent[a];
    }
    
    bool merge(int a, int b) {
        if (find(a) == find(b)) {
            return false;
        }
        
        parent[find(a)] = b;
        count--;
        
        return true;
    }
    
    bool isOne() {
        return count == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        UnionFind bob(n), alice(n);
        
        for (const vector<int>& edge: edges) {
            if (edge[0] != 3) {
                continue;
            }
            
            int u = edge[1],
                v = edge[2];
            
            ans += (alice.merge(u, v) | bob.merge(u, v));
        }
        
        for (const vector<int>& edge: edges) {
            if (edge[0] == 3) {
                continue;
            }
            
            int u = edge[1],
                v = edge[2];
            
            if (edge[0] == 1) {
                ans += alice.merge(u, v);
            } else if (edge[0] == 2) {
                ans += bob.merge(u, v);
            }
        }
        
        return bob.isOne() and alice.isOne() ? size(edges) - ans : -1;
    }
};