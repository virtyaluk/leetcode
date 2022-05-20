class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        vector<vector<int>> dp(101, vector<int>(101, -1));
        
        sort(begin(houses), end(houses));
        
        return dfs(houses, dp, 0, k);
    }
    
    int minDist(vector<int>& houses, int i, int j) {
        int mid = houses[(i + j) / 2], ans = 0;
        
        for (int k = i; k <= j; k++) {
            ans += abs(houses[k] - mid);
        }
        
        return ans;
    }
    
    int dfs(vector<int>& houses, vector<vector<int>>& dp, int i, int k) {
        if (i == size(houses)) {
            return 0;
        }
        
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        
        if (k == 1) {
            dp[i][k] = minDist(houses, i, size(houses) - 1);
            
            return dp[i][k];
        }
        
        int dist = INT_MAX;
        
        for (int j = i; j < size(houses); j++) {
            dist = min(dist, minDist(houses, i, j) + dfs(houses, dp, j + 1, k - 1));
        }
        
        return dp[i][k] = dist;
    }
};