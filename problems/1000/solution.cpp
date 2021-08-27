class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = size(stones);
        
        if ((n - 1) % (k - 1)) {
            return -1;
        }
        
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> pre = {0};
        
        for (const int& stone: stones) {
            pre.push_back(stone + pre.back());
        }
        
        for (int len = k; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                for (int mid = i; mid < j; mid += (k - 1)) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                }
                
                if ((j - i) % (k - 1) == 0) {
                    dp[i][j] += pre[j + 1] - pre[i];
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

/*
[3,5,1,2,6]
[3,8,9,11,17]

*/