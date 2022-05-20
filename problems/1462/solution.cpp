class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        unordered_map<int, unordered_set<int>> g;
        
        for (const vector<int>& pr: prerequisites) {
            g[pr[0]].insert(pr[1]);
        }
        
        for (const vector<int>& q: queries) {
            vector<bool> visited(n);
    
            ans.push_back(dfs(g, visited, q[0], q[1]));
        }
        
        return ans;
    }
    
    bool dfs(unordered_map<int, unordered_set<int>>& g, vector<bool>& visited, int start, int end) {
        if (start == end) {
            return true;
        }
        
        if (visited[start]) {
            return false;
        }
        
        visited[start] = true;
        
        for (const int& next: g[start]) {
            if (not visited[next]) {
                if (dfs(g, visited, next, end)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};