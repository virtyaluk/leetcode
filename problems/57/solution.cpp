class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int intStart = newInterval[0], intEnd = newInterval[1];
        int idx = 0, n = intervals.size();
        
        while (idx < n && intStart > intervals[idx][0]) {
            ans.push_back(intervals[idx]);
            idx++;
        }
        
        if (ans.empty() || ans.back()[1] < intStart) {
            ans.push_back(newInterval);
        } else {
            ans.back()[1] = max(ans.back()[1], intEnd);
        }
        
        while (idx < n) {
            vector<int> interval = intervals[idx];
            int start = interval[0], end = interval[1];
            idx++;
            
            if (ans.back()[1] < start) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = max(ans.back()[1], end);
            }
        }
        
        return ans;
    }
};