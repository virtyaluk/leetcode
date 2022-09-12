class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        unordered_map<int, unordered_set<int>> g;
        
        for (const vector<int>& road: roads) {
            g[road[0]].insert(road[1]);
            g[road[1]].insert(road[0]);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                
                int curRank = size(g[i]) + size(g[j]);
                
                if (g[i].count(j) or g[j].count(i)) {
                    curRank--;
                }
                
                ans = max(ans, curRank);
            }
        }
        
        return ans;
    }
};