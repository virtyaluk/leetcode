class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(size(stoneValue));
        int alice = dfs(dp, stoneValue, 0);
        
        if (alice > 0) {
            return "Alice";
        } else if (alice < 0) {
            return "Bob";
        }
        
        return "Tie";
    }
    
    int dfs(vector<int>& dp, const vector<int>& stones, int idx) {
        if (idx >= size(stones)) {
            return 0;
        }
        
        if (dp[idx]) {
            return dp[idx];
        }
        
        int ans = stones[idx] - dfs(dp, stones, idx + 1);
        
        if (idx + 1 < size(stones)) {
            ans = max(ans, stones[idx] + stones[idx + 1] - dfs(dp, stones, idx + 2));
        }
        
        if (idx + 2 < size(stones)) {
            ans = max(ans, stones[idx] + stones[idx + 1] + stones[idx + 2] - dfs(dp, stones, idx + 3));
        }
        
        return dp[idx] = ans;
    }
};