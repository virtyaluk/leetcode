class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < 1 << nums.size(); i++) {
            vector<int> subset;
            
            for (int j = 0; j < nums.size(); j++) {
                if (not (i & (1 << j))) {
                    subset.push_back(nums[j]);
                }
            }
            
            ans.push_back(subset);
        }
        
        return ans;
    }
    
    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> ans = {};
        int n = nums.size();
        function<void(vector<int>, int)> backtrack;
        
        backtrack = [&](vector<int> subset, int len) {
            ans.push_back(subset);
            
            for (int i = len; i < n; i++) {
                subset.push_back(nums[i]);
                backtrack(subset, i + 1);
                subset.pop_back();
            }
        };
        
        backtrack({}, 0);
        
        return ans;
    }
};