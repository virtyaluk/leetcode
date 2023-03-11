class Solution {
private:
    int ans = 0;
    int dfs(unordered_map<int, vector<int>>& g, string& s, int u) {
        vector<int> paths;
        
        for (const int& next: g[u]) {
            if (s[u] != s[next]) {
                paths.push_back(1 + dfs(g, s, next));
            } else {
                ans = max(ans, dfs(g, s, next));
            }
        }
        
        sort(begin(paths), end(paths), greater<>());
        
        if (size(paths) >= 2) {
            ans = max(ans, paths.front() + paths[1]);
        } else if (empty(paths)) {
            return 0;
        }
        
        return paths.front();
    }
public:
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int, vector<int>> g;
        
        for (int i = 0; i < size(parent); i++) {
            g[parent[i]].push_back(i);
        }
        
        ans = max(ans, dfs(g, s, 0));
        
        return ans + 1;
    }
};