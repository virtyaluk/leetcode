const int MOD = 1e9 + 7;

class Solution {
public:
    // int dp[101][101][101] = {-1};
    vector<vector<vector<int>>> dp;
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp = vector<vector<vector<int>>>(101, vector<vector<int>>(101, vector<int>(1001, -1)));
        
        return dfs(group, profit, n, minProfit, 0);
    }
    
    int dfs(
        vector<int>& group,
        vector<int>& profit,
        int n,
        int minProfit,
        int idx
    ) {
        if (n < 0) {
            return 0;
        }
        
        if (idx >= size(group)) {
            return minProfit <= 0 and n >= 0;
        }
        
        if (dp[n][idx][minProfit] != -1) {
            return dp[n][idx][minProfit];
        }
        
        int ans = dfs(group, profit, n, minProfit, idx + 1) % MOD;
        
        ans = (ans + dfs(group, profit, n - group[idx], max(0, minProfit - profit[idx]), idx + 1)) % MOD;
        
        return dp[n][idx][minProfit] = ans;
    }
};