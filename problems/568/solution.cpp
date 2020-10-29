class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        if (empty(days) or empty(flights)) {
            return 0;
        }
        
        vector<vector<int>> dp(size(days), vector<int>(size(days.front()) + 1));
        
        for (int week = size(days.front()) - 1; week >= 0; week--) {
            for (int curCity = 0; curCity < size(days); curCity++) {
                dp[curCity][week] = days[curCity][week] + dp[curCity][week + 1];
                
                for (int destCity = 0; destCity < size(days); destCity++) {
                    if (flights[curCity][destCity]) {
                        dp[curCity][week] = max(
                            days[destCity][week] + dp[destCity][week + 1],
                            dp[curCity][week]
                        );
                    }
                }
            }
        }
        
        return dp.front().front();
    }
};