class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int ans = 0, n = size(stones);
        vector<int> visited(n);
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            
            ans += dfs(stones, visited, i, n);
        }
        
        return ans;
    }
    
    int dfs(vector<vector<int>>& stones, vector<int>& visited, int idx, int n) {
        int ans = 0;
        visited[idx] = true;
        
        for (int i = 0; i < n; i++) {
            if (not visited[i] and (stones[i][0] == stones[idx][0] or stones[i][1] == stones[idx][1])) {
                ans += 1 + dfs(stones, visited, i, n);
            }
        }
        
        return ans;
    }
};


/*
110
101
011

*/