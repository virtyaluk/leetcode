class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1)),
            ans(n, vector<int>(n));
        
        for (const vector<int>& q: queries) {
            int row1 = q[0],
                col1 = q[1],
                row2 = q[2],
                col2 = q[3];
            dp[row1][col1]++;
            dp[row2 + 1][col1]--;
            dp[row1][col2 + 1]--;
            dp[row2 + 1][col2 + 1]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = i == 0 ? 0 : ans[i - 1][j],
                    x2 = j == 0 ? 0 : ans[i][j - 1],
                    x3 = i == 0 or j == 0 ? 0 : ans[i - 1][j - 1];
                ans[i][j] = dp[i][j] + x1 + x2 - x3;
            }
        }

        return ans;
    }
};