class TreeAncestor {
private:
    vector<vector<int>> up;

public:
    TreeAncestor(int n, vector<int>& parent) {
        up.resize(n, vector<int>(20, -1));
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }
        
        for (int i = 0; i < n; i++) {
            for (int k = 1; k < 20; k++) {
                if (up[i][k - 1] == -1) {
                    continue;
                }
                
                up[i][k] = up[up[i][k - 1]][k - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {        
        int anc = node;
        
        for (int i = 19; i >= 0 and k > 0; i--) {
            int r = 1 << i;
            
            if (k >= r) {
                k -= r;
                anc = up[anc][i];
                
                if (anc == -1) {
                    return -1;
                }
            }
        }
        
        return anc;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */