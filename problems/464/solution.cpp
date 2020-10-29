class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) < desiredTotal * 2) {
            return false;
        }
        
        vector<int> dp(1 << (maxChoosableInteger + 1));
        
        return dfs(dp, maxChoosableInteger, desiredTotal, 0);
    }
    
    bool dfs(vector<int>& dp, int m, int t, int mask) {
        if (dp[mask] != 0) {
            return dp[mask] == 1;
        }
        
        for (int i = m; i >= 1; i--) {
            if ((mask >> i) & 1) {
                continue;
            }
            
            if (i >= t or not dfs(dp, m, t - i, mask | (1 << i))) {
                dp[mask] = 1;
                
                return true;
            }
        }
        
        dp[mask] = -1;
        
        return false;
    }
};