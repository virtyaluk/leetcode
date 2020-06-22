class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n < 2) {
            vector<int> centroids;
            
            for (int i = 0; i < n; i++) {
                centroids.push_back(i);
            }
            
            return centroids;
        }
        
        map<int, set<int>> g;
        
        for (vector<int> edge: edges) {
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        
        vector<int> leaves;
        
        for (int i = 0; i < n; i++) {
            if (g[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        
        int remNodes = n;
        
        while (remNodes > 2) {
            remNodes -= leaves.size();
            vector<int> newLeaves;
            
            for (int leaf: leaves) {
                for (int next: g[leaf]) {
                    g[next].erase(leaf);
                    
                    if (g[next].size() == 1) {
                        newLeaves.push_back(next);
                    }
                }
            }
            
            leaves = newLeaves;
        }
        
        return leaves;
    }
};