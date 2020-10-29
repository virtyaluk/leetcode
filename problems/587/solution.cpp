class Solution {
public:
    int orientation(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> ans;
        
        sort(begin(trees), end(trees), [](const vector<int>& lhs, const vector<int>& rhs) {
            if (lhs.front() - rhs.front() == 0) {
                return lhs.back() < rhs.back();
            }
            
            return lhs.front() < rhs.front();
        });
        
        for (int i = 0; i < size(trees); i++) {
            while (size(ans) > 1 and orientation(ans[size(ans) - 2], ans.back(), trees[i]) < 0) {
                ans.pop_back();
            }
            
            ans.push_back(trees[i]);
        }
        
        if (size(ans) == size(trees)) {
            return ans;
        }
        
        for (int i = size(trees) - 2; i >= 0; i--) {
            while (size(ans) > 1 and orientation(ans[size(ans) - 2], ans.back(), trees[i]) < 0) {
                ans.pop_back();
            }
            
            ans.push_back(trees[i]);
        }
        
        ans.pop_back();
        
        return ans;
    }
};