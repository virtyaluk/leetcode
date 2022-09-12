class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        int m = size(targetPath);
        vector<vector<int>> dp(m, vector<int>(n, m + 1)),
            p(m, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            dp.front()[i] = names[i] != targetPath.front();
        }
        
        for (int i = 1; i < size(targetPath); i++) {
            for (vector<int> road: roads) {
                for (int j = 0; j < 2; j++) {
                    int u = road[j],
                        v = road[j ^ 1],
                        cur = dp[i - 1][u] + (names[v] != targetPath[i]);
                    
                    if (cur < dp[i][v]) {
                        dp[i][v] = cur;
                        p[i][v] = u;
                    }
                }
            }
        }
        
        int v = min_element(begin(dp.back()), end(dp.back())) - begin(dp.back());
        vector<int> ans{v};
        
        for (int i = m - 1; i > 0; i--) {
            v = p[i][v];
            ans.push_back(v);
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};