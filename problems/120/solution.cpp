class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int r = triangle.size() - 2; r >= 0; r--) {
            for (int c = 0; c < triangle[r].size(); c++) {
                triangle[r][c] += min(triangle[r + 1][c], triangle[r + 1][c + 1]);
            }
        }
        
        return triangle[0][0];
    }
    
    int minimumTotal2(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size() + 1);
        
        for (int r = triangle.size() - 1; r >= 0; r--) {
            for (int c = 0; c < triangle[r].size(); c++) {
                dp[c] = min(dp[c], dp[c + 1]) + triangle[r][c];
            }
        }
        
        return dp[0];
    }
    
    int minimumTotal1(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[0];
        
        for (int i = 1; i < n; i++) {
            vector<int> newDp(n);
            
            for (int j = 0; j <= i ; j++) {
                if (not j) {
                    newDp[j] = triangle[i][j] + dp[j];
                } else if (j == i) {
                    newDp[j] = triangle[i][j] + dp[j - 1];
                } else {
                    newDp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
                }
            }
            
            dp = newDp;
        }
        
        return *min_element(begin(dp), end(dp));
    }
};