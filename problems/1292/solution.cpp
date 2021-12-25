class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = size(mat),
            n = size(mat.back()),
            lo = 0,
            hi = min(m, n),
            ans = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = mat[i][j];
                
                if (i) {
                    dp[i][j] += dp[i - 1][j];
                }
                
                if (j) {
                    dp[i][j] += dp[i][j - 1];
                }
                
                if (i and j) {
                    dp[i][j] -= dp[i - 1][j - 1];
                }
            }
        }
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(dp, mid, threshold)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid -1;
            }
        }
        
        return ans;
    }
    
    bool check(vector<vector<int>>& dp, int k, int t) {
        for (int i = k - 1; i < size(dp); i++) {
            for (int j = k - 1; j < size(dp.back()); j++) {
                int sum = dp[i][j];
                
                if (i - k >= 0) {
                    sum -= dp[i - k][j];
                }
                
                if (j - k >= 0) {
                    sum -= dp[i][j - k];
                }
                
                if (i - k >= 0 and j - k >= 0) {
                    sum += dp[i - k][j - k];
                }
                
                if (sum <= t) {
                    return true;
                }
            }
        }
        
        return false;
    }
};