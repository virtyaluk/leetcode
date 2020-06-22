class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0, cur = 0;
        vector<pair<int, int>> line;
        
        for (const vector<int>& interval: intervals) {
            line.push_back({interval[0], 1});
            line.push_back({interval[1], -1});
        }
        
        sort(begin(line), end(line));
        
        for (auto [ignore, change]: line) {
            cur += change;
            ans = max(ans, cur);
        }
        
        return ans;
    }
};