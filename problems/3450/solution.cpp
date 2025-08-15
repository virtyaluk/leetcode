class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        int ans = 0;
        unordered_map<int, unordered_set<int>> um;

        for (const vector<int>& s: students) {
            um[s.back()].insert(s.front());
            ans = max(ans, (int) size(um[s.back()]));
        }

        return ans;
    }
};