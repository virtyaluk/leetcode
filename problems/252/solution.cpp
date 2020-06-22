class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& l, vector<int>& r) {
            return l[0] < r[0];
        });
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        
        return true;
    }
};