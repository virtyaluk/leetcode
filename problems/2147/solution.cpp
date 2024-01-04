const int MOD = 1e9 + 7;

class Solution {
private:
    int dfs(vector<vector<int>>& dp, const string& corridor, int idx, int seats) {
        if (idx == size(corridor)) {
            return seats == 2 ? 1 : 0;
        }
        
        if (dp[idx][seats] != -1) {
            return dp[idx][seats];
        }
        
        int ans = 0;
        
        if (seats == 2) {
            if (corridor[idx] == 'S') {
                ans = dfs(dp, corridor, idx + 1, 1);
            } else {
                ans = (dfs(dp, corridor, idx + 1, 0) + dfs(dp, corridor, idx + 1, 2)) % MOD;
            }
        } else {
            if (corridor[idx] == 'S') {
                ans = dfs(dp, corridor, idx + 1, seats + 1);
            } else {
                ans = dfs(dp, corridor, idx + 1, seats);
            }
        }
        
        return dp[idx][seats] = ans;
    }
public:
    int numberOfWays(string corridor) {
        vector<vector<int>> dp(size(corridor), vector<int>(3, -1));
        
        return dfs(dp, corridor, 0, 0);
    }
};