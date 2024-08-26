class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans = 0;
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        
        for (int i = 0; i < size(original); i++) {
            int u = original[i] - 'a',
                v = changed[i] - 'a';
            
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] != INT_MAX and dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        for (int i = 0; i < size(source); i++) {
            if (source[i] == target[i]) {
                continue;
            }
            
            int u = source[i] - 'a',
                v = target[i] - 'a';
            
            if (dist[u][v] == INT_MAX) {
                return -1;
            }
            
            ans += dist[u][v];
        }
        
        return ans;
    }
};