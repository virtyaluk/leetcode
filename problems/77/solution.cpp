class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> candidate;
        
        backtrack(n, k, 1, candidate, ans);
        
        return ans;
    }
    
    void backtrack(const int n, const int k, int start, vector<int>& candidate, vector<vector<int>>& ans) {
        if (candidate.size() == k) {
            ans.push_back(candidate);
            return;
        }
        
        for (int num = start; num <= n; num++) {
            candidate.push_back(num);
                
            backtrack(n, k, num + 1, candidate, ans);
                
            candidate.pop_back();
        }
    }
};