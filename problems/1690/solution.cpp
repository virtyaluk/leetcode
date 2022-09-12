class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = size(stones);
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> prefSum(n + 1);
        
        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + stones[i];
        }
        
        for (int len = 2; len <= n; len++) {
            for (int start = 0; start + len - 1 < n; start++) {
                int end = start + len - 1;
                int scoreRemoveFirst = prefSum[end + 1] - prefSum[start + 1],
                    scoreRemoveLast = prefSum[end] - prefSum[start];
                
                dp[start][end] = max(
                    scoreRemoveFirst - dp[start + 1][end],
                    scoreRemoveLast - dp[start][end - 1]
                );
            }
        }
        
        return dp[0].back();
    }
    
    int stoneGameVII1(vector<int>& stones) {
        int sum = accumulate(begin(stones), end(stones), 0);
        vector<vector<int>> dp(stones.size() + 1, vector<int>(stones.size() + 1, -1));
        
        return helper(stones, dp, 0, stones.size() - 1, sum, true);
    }
    
    int helper(vector<int>& stones, vector<vector<int>>& dp, int start, int end, int sum, bool aliceTurn) {
        if (start == end) {
            return 0;
        }
        
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        
        int dif = 0,
            scoreRemoveFirst = sum - stones[start],
            scoreRemoveLast = sum - stones[end];
        
        if (aliceTurn) {
            dif = max(
                helper(stones, dp, start + 1, end, sum - stones[start], !aliceTurn) + scoreRemoveFirst,
                helper(stones, dp, start, end - 1, sum - stones[end], !aliceTurn) + scoreRemoveLast
            );
        } else {
            dif = min(
                helper(stones, dp, start + 1, end, sum - stones[start], !aliceTurn) - scoreRemoveFirst,
                helper(stones, dp, start, end - 1, sum - stones[end], !aliceTurn) - scoreRemoveLast
            );
        }
        
        return dp[start][end] = dif;
    }
};