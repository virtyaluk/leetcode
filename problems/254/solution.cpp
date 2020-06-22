class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        if (n <= 3) {
            return {};
        }
        
        vector<vector<int>> ans;
        vector<int> cur;
        
        backtrack(n, cur, ans);
        
        return ans;
    }
    
    void backtrack(int n, vector<int>& cur, vector<vector<int>>& ans) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0 and (empty(cur) or i >= cur.back())) {
                cur.push_back(i);
                cur.push_back(n / i);
                ans.push_back(cur);
                cur.pop_back();
                
                backtrack(n / i, cur, ans);
                
                cur.pop_back();
            }
        }
    }
};