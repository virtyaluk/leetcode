class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = size(nums);
        vector<vector<int>> ans;
        vector<int> cand;
        function<void(int)> backtrack;
        
        backtrack = [&](int idx) {
            ans.push_back(cand);
            
            for (int i = idx; i < n; i++) {
                if (i != idx and nums[i] == nums[i - 1]) {
                    continue;
                }
                
                cand.push_back(nums[i]);

                backtrack(i + 1);

                cand.pop_back();
            }
        };
        
        sort(begin(nums), end(nums));
        backtrack(0);
        
        return ans;
    }
};