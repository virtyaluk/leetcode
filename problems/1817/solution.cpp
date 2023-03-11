class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> uams;
        vector<int> ans(k);
        
        for (const vector<int>& log: logs) {
            uams[log[0]].insert(log[1]);
        }
        
        for (auto [userId, uniqueMinutes]: uams) {
            ans[size(uniqueMinutes) - 1]++;
        }
        
        return ans;
    }
};