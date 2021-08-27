class DisjointSet {
private:
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        
        iota(begin(parent), end(parent), 0);
    }
    
    int find(int a) {        
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
        
        if (size[pa] > size[pb]) {
            parent[pb] = pa;
            size[pa] += size[pb];
        } else {
            parent[pa] = pb;
            size[pb] += size[pa];
        }
        
        return true;
    }
    
    int sizeOf(int a) {
        return size[a];
    }
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = size(graph), ans = INT_MAX, componentSize = INT_MIN;
        DisjointSet ds(n + 2);
        unordered_map<int, int> freq;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1) {
                    ds.merge(i, j);
                }
            }
        }
        
        for (int i = 0; i < size(initial); i++) {
            int pi = ds.find(initial[i]);

            freq[pi]++;
        }
        
        for (int i = 0; i < size(initial); i++) {
            int pi = ds.find(initial[i]);
            
            if (freq[pi] == 1) {
                if (ds.sizeOf(pi) == componentSize) {
                    ans = min(ans, initial[i]);
                } else if (ds.sizeOf(pi) > componentSize) {
                    componentSize = ds.sizeOf(pi);
                    ans = initial[i];
                }
            }
        }
        
        if (ans == INT_MAX) {
            return *min_element(begin(initial), end(initial));
        }
        
        return ans;
    }
};