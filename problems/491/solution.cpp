class Solution {
private:
    void solve(const vector<int>& nums, vector<int>& cur, const int idx, vector<vector<int>>& ans) {
        if (idx >= size(nums)) {
            if (size(cur) > 1) {
                ans.push_back(cur);
            }
            
            return;
        }
        
        if (not idx or empty(cur) or nums[idx] >= cur.back()) {
            cur.push_back(nums[idx]);
            
            solve(nums, cur, idx + 1, ans);
            
            cur.pop_back();
        }
        
        if (empty(cur) or cur.back() != nums[idx]) {
            solve(nums, cur, idx + 1, ans);
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        
        solve(nums, cur, 0, ans);
        
        return ans;
    }
};