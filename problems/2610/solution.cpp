class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<unordered_set<int>> arr(200);
        
        for (const int& num: nums) {
            for (unordered_set<int>& us: arr) {
                if (not us.count(num)) {
                    us.insert(num);
                    break;
                }
            }
        }
        
        for (unordered_set<int>& us: arr) {
            if (empty(us)) {
                continue;
            }
            
            ans.push_back({begin(us), end(us)});
        }
        
        return ans;
    }
};