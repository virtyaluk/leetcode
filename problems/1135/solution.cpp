class Solution {
private:
    int find(vector<int>& parent, int i) {
        while (parent[i] != i) {
            i = parent[i];
        }
        
        return i;
    }
    
    bool join(vector<int>& parent, int i, int j) {
        int pi = find(parent, i),
            pj = find(parent, j);
        
        if (pi == pj) {
            return false;
        }
        
        parent[pi] = pj;
        
        return true;
    }
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        int ans = 0;
        vector<int> parent(n + 1);
        
        iota(begin(parent), end(parent), 0);
        sort(begin(connections), end(connections), [](const vector<int>& a, const vector<int>& b) {
            return a[2] <= b[2];
        });
        
        for (const vector<int>& con: connections) {
            int u = con[0], v = con[1], cost = con[2];
            
            if (join(parent, u, v)) {
                ans += cost;
                n--;
            }
        }
        
        return n == 1 ? ans : -1;
    }
};