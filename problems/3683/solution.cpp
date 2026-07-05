class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;

        for (const vector<int>& t: tasks) {
            ans = min(ans, t.front() + t.back());
        }

        return ans;
    }
};