class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n) {
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
        
        return true;
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool> ans;
        UnionFind uf(n + 1);
        
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = 1; j * i <= n; j++) {
                uf.merge(i, i * j);
            }
        }
        
        for (auto& q: queries) {
            ans.push_back(uf.find(q[0]) == uf.find(q[1]));
        }
        
        return ans;
    }
};