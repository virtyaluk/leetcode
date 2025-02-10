class Solution {
private:
    int dist(vector<vector<int>>& g, int n) {
        vector<int> dp(n);
        
        for (int node = n - 2; node >= 0; node--) {
            int minDist = n;
            
            for (const int& next: g[node]) {
                minDist = min(minDist, dp[next] + 1);
            }
            
            dp[node] = minDist;
        }
        
        return dp.front();
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        vector<int> ans;
        
        for (int i = 0; i < n - 1; i++) {
            g[i].push_back(i + 1);
        }
        
        for (const vector<int>& q: queries) {
            int u = q.front(),
                v = q.back();
            g[u].push_back(v);
            
            ans.push_back(dist(g, n));
        }
        
        return ans;
    }
};