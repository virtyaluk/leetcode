class Solution {
private:
    int dfs(const vector<int>& rods, vector<vector<int>>& dp, int i, int dif) {
        if (i == size(rods)) {
            if (not dif) {
                return 0;
            }
            
            return -1e9;
        }
        
        if (dp[i][5000 + dif] == -1) {
            dp[i][5000 + dif] = max({
                dfs(rods, dp, i + 1, dif),
                dfs(rods, dp, i + 1, dif - rods[i]),
                rods[i] + dfs(rods, dp, i + 1, dif + rods[i])
            });
        }
        
        return dp[i][5000 + dif];
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int n = size(rods);
        vector<vector<int>> dp(n, vector<int>(10000, -1));
        
        return dfs(rods, dp, 0, 0);
    }
};