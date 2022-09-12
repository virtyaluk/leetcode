class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = size(cuts);
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        
        sort(begin(cuts), end(cuts));
        
        return dfs(dp, cuts, 0, m, n);
    }
    
    int dfs(vector<vector<int>>& dp, vector<int>& cuts, int i, int j, int n) {
        if (i >= j) {
            return 0;
        }
        
        if (dp[i][j] == -1) {
            dp[i][j] = INT_MAX;
            
            int cost = (j == size(cuts) ? n : cuts[j]) - (i == 0 ? 0 : cuts[i - 1]);
            
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], cost + dfs(dp, cuts, i, k, n) + dfs(dp, cuts, k + 1, j, n));
            }
        }
        
        return dp[i][j];
    }
};