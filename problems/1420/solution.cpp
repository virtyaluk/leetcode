const int MOD = 1e9 + 7;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        
        return dfs(dp, n, m, k, 0, 0, 0);
    }
    
    int dfs(vector<vector<vector<int>>>& dp, int n, int m, int k, int i, int curMax, int curCost) {
        if (i >= n) {
            return k == curCost;
        }
        
        if (dp[i][curMax][curCost] != -1) {
            return dp[i][curMax][curCost];
        }
        
        int ans = 0;
        
        for (int num = 1; num <= m; num++) {
            int newMax = curMax, newCost = curCost;
            
            if (num > curMax) {
                newMax = num;
                newCost++;
            }
            
            if (newCost > k) {
                break;
            }
            
            ans = (ans + dfs(dp, n, m, k, i + 1, newMax, newCost)) % MOD;
        }
        
        return dp[i][curMax][curCost] = ans;
    }
};