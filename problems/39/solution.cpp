class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = size(candidates);
        vector<vector<int>> ans;
        vector<int> cand;
        function<void(int, int, vector<int>&)> backtrack;
        
        backtrack = [&](int remain, int idx, vector<int>& candidate) {
            if (not remain) {
                ans.push_back(candidate);
                return;
            } else if (remain < 0) {
                return;
            }
            
            for (int i = idx; i < n; i++) {
                candidate.push_back(candidates[i]);
                
                backtrack(remain - candidates[i], i, candidate);
                
                candidate.pop_back();
            }
        };
        
        backtrack(target, 0, cand);
        
        return ans;
    }
};