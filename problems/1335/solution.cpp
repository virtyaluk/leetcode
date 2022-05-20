class Solution {
public:
    int minDifficulty(vector<int>& jobs, int d) {
        int n = size(jobs);
        
        if (n < d) {
            return -1;
        }
        
        vector<vector<int>> dp(d - 1, vector<int>(n, -1));
        
        return dfs(d - 1, 0, jobs, dp);
    }
    
    int dfs(int d, int pos, vector<int>& jobs, vector<vector<int>>& dp) {
        if (not d) {
            return *max_element(begin(jobs) + pos, end(jobs));
        }
        
        int day = size(dp) - d;
        
        if (dp[day][pos] != -1) {
            return dp[day][pos];
        }
        
        int m = INT_MAX, M = INT_MIN;
        
        for (int i = pos; i < size(jobs) - d; i++) {
            M = max(M, jobs[i]);
            m = min(m, M + dfs(d - 1, i + 1, jobs, dp));
        }
        
        return dp[day][pos] = m;
    }
};