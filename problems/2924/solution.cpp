class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> g;
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            g[i] = 0;
        }
        
        for (const vector<int>& e: edges) {
            g[e.back()]++;
        }
        
        for (const auto& [u, indeg]: g) {
            if (indeg == 0) {
                ans.push_back(u);
            }
        }
        
        if (size(ans) == 1) {
            return ans.front();
        }
        
        return -1;
    }
};