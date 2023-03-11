class Solution {
private:
    int dfs(
            vector<vector<int>>& graph,
            string& colors,
            vector<int>& visited,
            vector<vector<int>>& freq,
            int i) {
        if (not visited[i]) {
            visited[i] = 1;
            
            for (const int& next: graph[i]) {
                if (dfs(graph, colors, visited, freq, next) == INT_MAX) {
                    return INT_MAX;
                }
                
                for (int k = 0; k < 26; k++) {
                    freq[i][k] = max(freq[i][k], freq[next][k]);
                }
            }
            
            freq[i][colors[i] - 'a']++;
            
            visited[i] = 2;
        }
        
        return visited[i] == 2 ? freq[i][colors[i] - 'a'] : INT_MAX;
    }
    
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> graph(size(colors)), freq(size(colors), vector<int>(26));
        vector<int> visited(size(colors));
        
        for (const vector<int>& e: edges) {
            graph[e[0]].push_back(e[1]);
        }
        
        for (int i = 0; i < size(colors) and ans != INT_MAX; i++) {
            ans = max(ans, dfs(graph, colors, visited, freq, i));
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};