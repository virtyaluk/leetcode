const int MAX = 1e7;

class Solution {
private:
    int dp[101][101][22];
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        
        int ans = dfs(houses, cost, 0, target, 0);
        
        return ans > MAX ? -1 : ans;
    }
    
    int dfs(
        vector<int>& houses,
        vector<vector<int>>& cost,
        int i,
        int target,
        int color
    ) {
        if (i >= size(houses) or target < 0) {
            return not target ? 0 : MAX + 1;
        }
        
        if (houses[i] != 0) {
            return dfs(houses, cost, i + 1, target - (color != houses[i]), houses[i]);
        }
        
        if (dp[i][target][color] != -1) {
            return dp[i][target][color];
        }
        
        int ans = MAX + 1;
        
        for (int j = 1; j <= size(cost[i]); j++) {
            ans = min(ans, cost[i][j - 1] + dfs(houses, cost, i + 1, target - (color != j), j));
        }
        
        return dp[i][target][color] = ans;
    }
};