class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = size(s);
        unordered_map<int, unordered_set<int>> g;
        vector<bool> visited(n);
        vector<int> indices;
        string indicesStr;
        function<void(int)> dfs;
        
        dfs = [&](int idx) {
            visited[idx] = true;
            
            indices.push_back(idx);
            indicesStr.push_back(s[idx]);
            
            for (int next: g[idx]) {
                if (not visited[next]) {
                    dfs(next);
                }
            }
        };
        
        for (const vector<int>& p: pairs) {
            g[p[0]].insert(p[1]);
            g[p[1]].insert(p[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            
            indices.clear();
            indicesStr.clear();
            
            dfs(i);
            
            sort(begin(indices), end(indices));
            sort(begin(indicesStr), end(indicesStr));
            
            for (int idx = 0; idx < size(indices); idx++) {
                s[indices[idx]] = indicesStr[idx];
            }
        }
        
        return s;
    }
};