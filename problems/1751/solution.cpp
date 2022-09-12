class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        unordered_map<string, int> dp;
        
        sort(begin(events), end(events));
        
        return dfs(dp, events, k, 0, 0);
    }
    
    int dfs(
        unordered_map<string, int>& dp,
        vector<vector<int>>& events,
        int k,
        int lastEnd,
        int j
    ) {
        if (not k or j >= size(events)) {
            return 0;
        }
        
        string key = to_string(k) + "_" + to_string(lastEnd);
        
        if (dp.count(key)) {
            return dp[key];
        }
        
        int ans = dfs(dp, events, k, lastEnd, j + 1);
        
        if (events[j][0] > lastEnd) {
            ans = max(ans, events[j][2] + dfs(dp, events, k - 1, events[j][1], j + 1));
        }
        
        return dp[key] = ans;
    }
};