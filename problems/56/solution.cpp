class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (empty(intervals)) {
            return {};
        }
        
        vector<vector<int>> ans;
        
        sort(begin(intervals), end(intervals));
        
        for (const vector<int>& interval: intervals) {
            if (empty(ans) or interval.front() > ans.back().back()) {
                ans.push_back(interval);
            } else {
                ans.back().back() = max(ans.back().back(), interval.back());
            }
        }
        
        return ans;
    }
};