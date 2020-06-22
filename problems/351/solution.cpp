class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int ans = 0;
        vector<bool> visited(10);
        vector<vector<int>> skip(10, vector<int>(10));
        
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[7][9] = skip[9][7] = 8;
        skip[3][9] = skip[9][3] = 6;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
        
        for (int i = m; i <= n; i++) {
            ans += dfs(visited, skip, 1, i - 1) * 4;
            ans += dfs(visited, skip, 2, i - 1) * 4;
            ans += dfs(visited, skip, 5, i - 1);
        }
        
        return ans;
    }
    
    int dfs(vector<bool>& visited, vector<vector<int>>& skip, int cur, int remain) {
        if (not remain) {
            return 1;
        }
        
        int ans = 0;
        visited[cur] = true;
        
        for (int i = 1; i < 10; i++) {
            if (not visited[i] and (skip[cur][i] == 0 or visited[skip[cur][i]])) {
                ans += dfs(visited, skip, i, remain - 1);
            }
        }
        
        visited[cur] = false;
        return ans;
    }
};