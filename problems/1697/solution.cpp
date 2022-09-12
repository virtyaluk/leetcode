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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = size(queries);
        n = size(edgeList);
        vector<bool> ans(m);
        UnionFind uf(n + 1);
        int i = 0;
        
        for (int i = 0; i < m; i++) {
            queries[i].push_back(i);
        }
        
        sort(begin(edgeList), end(edgeList), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        
        sort(begin(queries), end(queries), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        
        for (auto& q: queries) {
            while (i < n and edgeList[i][2] < q[2]) {
                uf.merge(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            
            ans[q.back()] = uf.find(q[0]) == uf.find(q[1]);
        }
        
        return ans;
    }
};