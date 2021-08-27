class DisjointSet {
private:
    vector<int> parent;
    int groups;

public:
    DisjointSet(int n) {
        parent.resize(n);
        groups = n;
        
        iota(begin(parent), end(parent), 0);
    }
    
    int find(int a) {
//         if (parent[a] != a) {
//             parent[a] = find(parent[a]);
//         }
        
//         return parent[a];
        
        while (a != parent[a]) {
            a = parent[a];
        }
        
        return a;
    }
    
    bool merge(int a, int b) {
        int pa = find(a),
            pb = find(b);
        
        if (pa == pb) {
            return false;
        }
        
        parent[pa] = pb;
        groups--;
        
        return true;
    }
    
    int getGroups() {
        return groups;
    }
};

class Solution {
private:
    bool isSimilar(const string& a, const string& b) {
        int dif = 0;
        
        for (int i = 0; i < size(a); i++) {
            dif += (a[i] != b[i]);
        }
        
        return not dif or dif == 2;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = size(strs);
        DisjointSet ds(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    ds.merge(i, j);
                }
            }
        }
        
        return ds.getGroups();
    }
};