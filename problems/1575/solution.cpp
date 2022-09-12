const int MOD = 1e9 + 7;

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(size(locations), vector<int>(fuel + 1, -1));
        
        return dfs(dp, locations, start, finish, fuel);
    }
    
    int dfs(vector<vector<int>>& dp, vector<int>& loc, int i, int k, int f) {
        if (f < 0) {
            return 0;
        }
        
        if (dp[i][f] != -1) {
            return dp[i][f];
        }
        
        int ans = i == k;
        
        for (int j = 0; j < size(loc); j++) {
            if (i == j) {
                continue;
            }
            
            ans = (ans + dfs(dp, loc, j, k, f - abs(loc[i] - loc[j]))) % MOD;
        }
        
        return dp[i][f] = ans;
    }
};