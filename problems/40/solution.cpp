class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int, int)> backtrack;
        
        backtrack = [&](int idx, int remain) {
            if (remain == 0) {
                ans.push_back(cur);
                return;
            }
            
            for (int i = idx; i < candidates.size(); i++) {
                if (i > idx and candidates[i] == candidates[i - 1]) {
                    continue;
                }
                
                if (remain - candidates[i] < 0) {
                    break;
                }
                
                cur.push_back(candidates[i]);
                backtrack(i + 1, remain - candidates[i]);
                cur.pop_back();
            }
        };
        
        sort(begin(candidates), end(candidates));
        
        backtrack(0, target);
        
        return ans;
    }
};