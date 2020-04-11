class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& board) {
        int m = size(board), n = size(board.back());
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        function<int(int, int, int)> getHealth = [&](int curHealth, int i, int j) {
            if (i >= m or j >= n) {
                return INT_MAX;
            }
            
            return max(1, dp[i][j] - curHealth);
        };
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int curHealth = board[i][j],
                    nextHealth = min(getHealth(curHealth, i + 1, j), getHealth(curHealth, i, j + 1));
                
                if (nextHealth != INT_MAX) {
                    dp[i][j] = nextHealth;
                } else {
                    dp[i][j] = curHealth >= 0 ? 1 : 1 - curHealth;
                }
            }
        }
        
        return dp.front().front();
    }
};