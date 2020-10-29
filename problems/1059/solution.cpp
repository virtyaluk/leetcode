class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, unordered_set<int>> g;
        unordered_set<int> visited;
        
        for (const vector<int>& e: edges) {
            g[e[0]].insert(e[1]);
        }
        
        return dfs(g, visited, source, destination);
    }
    
    bool dfs(unordered_map<int, unordered_set<int>>& g, unordered_set<int>& visited, int s, int d) {
        if (visited.count(s)) {
            return false;
        }
        
        visited.insert(s);
        
        if (not g.count(s)) {
            visited.erase(s);
            return s == d;
        }
        
        for (const int& next: g[s]) {
            if (not dfs(g, visited, next, d)) {
                return false;
            }
        }
        
        visited.erase(s);

        return true;
    }
};