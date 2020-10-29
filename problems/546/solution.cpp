class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = size(boxes);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));
        
        return calculate(boxes, dp, 0, n - 1, 0);
    }
    
    int calculate(vector<int>& boxes, vector<vector<vector<int>>>& dp, int l, int r, int k) {
        if (l > r) {
            return 0;
        }
        
        while (r > l and boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        
        if (dp[l][r][k] != 0) {
            return dp[l][r][k];
        }
        
        dp[l][r][k] = calculate(boxes, dp, l, r - 1, 0) + pow(k + 1, 2);
        
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k],
                                  calculate(boxes, dp, l, i, k + 1) + calculate(boxes, dp, i + 1, r - 1, 0));
            }
        }
        
        return dp[l][r][k];
    }
};