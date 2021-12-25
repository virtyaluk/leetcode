class Solution {
public:
    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(101, vector<int>(101, -1)),
            pal(101, vector<int>(101, -1));
        
        return dfs(dp, pal, s, 0, k - 1);
    }
    
    int dfs(vector<vector<int>>& dp, vector<vector<int>>& pal, string& s, int pos, int k) {
        if (k == 0) {
            return cost(pal, s, pos, size(s) - 1);
        }
        
        if (pos >= size(s)) {
            return 1e2 + 3;
        }
        
        if (dp[pos][k] == -1) {
            dp[pos][k] = 1e2 + 3;
            
            for (int i = pos; i < size(s) - 1; i++) { // -1 to leave at least one char for the last k
                // if i == pos meaning 1 char to consider
                dp[pos][k] = min(dp[pos][k], cost(pal, s, pos, i) + dfs(dp, pal, s, i + 1, k - 1));
            }
        } 
        
        return dp[pos][k];
    }
    
    int cost(vector<vector<int>>& pal, string& s, int lo, int hi) {
        if (lo >= hi) {
            return 0;
        }
        
        if (pal[lo][hi] == -1) {
            pal[lo][hi] = (s[lo] != s[hi]) + cost(pal, s, lo + 1, hi - 1);
        }
        
        return pal[lo][hi];
    }
};