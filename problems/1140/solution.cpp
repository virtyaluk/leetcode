class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = size(piles), sum = accumulate(begin(piles), end(piles), 0);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        return (dfs(dp, piles, 1, 0) + sum) / 2;
    }
    
    int dfs(vector<vector<int>>& dp, const vector<int>& piles, int m, int i) {
        if (i >= size(piles)) {
            return 0;
        }
        
        if (dp[i][m] != -1) {
            return dp[i][m];
        }
        
        int ans = INT_MIN, curSum = 0;
        
        for (int j = i; j < size(piles) and j - i + 1 <= 2 * m; j++) {
            curSum += piles[j];
            ans = max(ans, curSum - dfs(dp, piles, max(m, j - i + 1), j + 1));
        }
        
        return dp[i][m] = ans;
    }
};