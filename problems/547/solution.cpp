class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> visited(n);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(isConnected, visited, i);
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, vector<bool>& visited, int i) {
        visited[i] = true;
        
        for (int j = 0; j < grid.size(); j++) {
            if (!visited[j] && grid[i][j] == 1) {
                dfs(grid, visited, j);
            }
        }
    }
};

/*

[
    [1,1,0],
    [1,1,0],
    [0,0,1]
]

*/