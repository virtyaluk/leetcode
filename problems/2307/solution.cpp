class Solution {
private:
    bool dfs(vector<vector<pair<int, double>>>& g, vector<double>& vis, int i, double val) {
        if (not vis[i]) {
            vis[i] = val;
            
            for (auto& [j, div]: g[i]) {
                if (dfs(g, vis, j, val / div)) {
                    return true;
                }
            }
        }
        
        return abs(vis[i] - val) >= 0.00001;
    }
public:
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, int> ids;
        vector<vector<pair<int, double>>> g(1000);
        vector<double> vis(1000);
        
        for (const vector<string>& eq: equations) {
            if (not ids.count(eq[0])) {
                ids[eq[0]] = size(ids);
            }
            
            if (not ids.count(eq[1])) {
                ids[eq[1]] = size(ids);
            }
        }
        
        for (int i = 0; i < size(equations); i++) {
            g[ids[equations[i][0]]].push_back({ids[equations[i][1]], values[i]});
            g[ids[equations[i][1]]].push_back({ids[equations[i][0]], 1.0 / values[i]});
        }
        
        for (int i = 0; i < size(ids); i++) {
            if (not vis[i] and dfs(g, vis, i, 1.0)) {
                return true;
            }
        }
        
        return false;
    }
};