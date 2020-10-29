class Solution {
private:
    int dp[101][101];
    unordered_map<char, unordered_set<int>> dists;
public:
    int findRotateSteps(string ring, string key) {
        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i < size(ring); i++) {
            dists[ring[i]].insert(i);
        }
        
        return size(key) + dfs(ring, key, 0, 0);
    }
    
    int dfs(string& ring, string& key, int i, int j) {
        if (j >= size(key)) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        
        for (const int& k: dists[key[j]]) {
            int dist = abs(k - i);
            
            ans = min(ans, min(dist, (int) size(ring) - dist) + dfs(ring, key, k, j + 1));
        }
        
        return dp[i][j] = ans;
    }
};