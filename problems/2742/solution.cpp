class Solution {
private:    
    int dfs(const vector<int>& cost, const vector<int>& time, vector<vector<int>>& dp, int idx, int remain) {
        if (remain <= 0) {
            return 0;
        }
        
        if (idx == size(cost)) {
            return 1e9;
        }

        if (dp[idx][remain] == -1) {
            int paint = cost[idx] + dfs(cost, time, dp, idx + 1, remain - 1 - time[idx]),
                notPaint = dfs(cost, time, dp, idx + 1, remain);
            
            dp[idx][remain] = min(paint, notPaint);
        }
        
        return dp[idx][remain];
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = size(cost);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        return dfs(cost, time, dp, 0, n);
    }
};