class Solution {
private:
    float dist(int x1, int y1, int x2, int y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
    }
    
    int dfs(const vector<vector<int>>& bombs, vector<bool>& visited, int idx) {
        if (visited[idx]) {
            return 0;
        }
        
        int ans = 1;
        visited[idx] = true;
        
        for (int i = 0; i < size(bombs); i++) {
            if (not visited[i] and dist(bombs[idx][0], bombs[idx][1], bombs[i][0], bombs[i][1]) <= bombs[idx][2]) {
                ans += dfs(bombs, visited, i);
            }
        }
        
        return ans;
    }
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0, n = size(bombs);
        
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n);
            ans = max(ans, dfs(bombs, visited, i));
        }
        
        return ans;
    }
};