class Solution {
private:
    pair<int, int> findDiamter(unordered_map<int, unordered_set<int>>& g, int node, int parent) {
        int diameter = 0,
            depth1 = 0,
            depth2 = 0;
        
        for (const int& next: g[node]) {
            if (next == parent) {
                continue;
            }
            
            auto [nextDiamter, nextDepth] = findDiamter(g, next, node);
            diameter = max(diameter, nextDiamter);
            nextDepth++;
            
            if (nextDepth > depth1) {
                depth2 = depth1;
                depth1 = nextDepth;
            } else if (nextDepth > depth2) {
                depth2 = nextDepth;
            }
        }
        
        diameter = max(diameter, depth1 + depth2);
        
        return {diameter, depth1};
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, unordered_set<int>> g1, g2;
        
        for (const vector<int>& e: edges1) {
            int u = e.front(),
                v = e.back();
            g1[u].insert(v);
            g1[v].insert(u);
        }
        
        for (const vector<int>& e: edges2) {
            int u = e.front(),
                v = e.back();
            g2[u].insert(v);
            g2[v].insert(u);
        }
        
        int d1 = findDiamter(g1, 0, -1).first,
            d2 = findDiamter(g2, 0, -1).first,
            d3 = ceil(d1 / 2.0) + ceil(d2 / 2.0) + 1;
        
        return max({d1, d2, d3});
    }
};