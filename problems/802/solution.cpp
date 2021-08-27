class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans,
            visited(size(graph)); // 0 - unvisited, 1 - visiting, 2 - safe node
        
        for (int i = 0; i < size(graph); i++) {
            if (dfs(graph, i, visited)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& visited) {
        if (visited[node]) {
            return visited[node] == 2;
        }
        
        visited[node] = 1;
        
        for (const int& next: graph[node]) {
            if (not dfs(graph, next, visited)) {
                return false;
            }
        }
        
        visited[node] = 2;
        
        return true;
    }
};