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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = size(edges), node = -1, a = -1, b = -1;
        vector<int> indegree(n + 1);
        UnionFind uf(n + 1);
        
        for (const vector<int>& edge: edges) {
            indegree[edge[1]]++;
            
            if (indegree[edge[1]] == 2) {
                node = edge[1];
                break;
            }
        }
        
        if (node != -1) {
            for (const vector<int>& edge: edges) {
                if (edge[1] != node) {
                    uf.merge(edge[0], edge[1]);
                } else if (a == -1) {
                    a = edge[0];
                } else {
                    b = edge[0];
                }
            }
            
            if (uf.find(a) == uf.find(node)) {
                return {a, node};
            } else {
                return {b,  node};
            }
        } else {
            for (const vector<int>& edge: edges) {
                if (not uf.merge(edge[0], edge[1])) {
                    return edge;
                }
            }
        }
        
        return {};
    }
};