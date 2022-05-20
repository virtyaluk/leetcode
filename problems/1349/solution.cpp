class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = size(seats),
            n = size(seats.front());
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, -1));
        
        return dfs(seats, dp, 0, 0);
    }
    
    int dfs(
        vector<vector<char>>& seats,
        vector<vector<int>>& dp,
        int row,
        int mask
    ) {
        if (row == size(seats)) {
            return 0;
        }
        
        if (dp[row][mask] == -1) {
            int ans = 0;
            vector<int> masks;
            
            backtrack(seats[row], 0, mask, 0, masks);
            
            for (const int& nextMask: masks) {
                ans = max(ans, __builtin_popcount(nextMask) + dfs(seats, dp, row + 1, nextMask));
            }
            
            dp[row][mask] = ans;
        }
        
        return dp[row][mask];
    }
    
    void backtrack(vector<char>& seats, int col, int prevMask, int mask, vector<int>& masks) {
        if (col == size(seats)) {
            masks.push_back(mask);
            
            return;
        }
        
        backtrack(seats, col + 1, prevMask, mask, masks);
        
        if (
            seats[col] != '#'
            and (col == 0 or ((mask & (1 << (col - 1))) == 0 and (prevMask & (1 << (col - 1))) == 0))
            and (col == size(seats) - 1 or ((prevMask & (1 << (col + 1))) == 0))
        ) {
            mask |= (1 << col);
            
            backtrack(seats, col + 1, prevMask, mask, masks);
            
            mask ^= (1 << col);
        }
    }
};