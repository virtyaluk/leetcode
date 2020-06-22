class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int idx = 0;
        
        dfs(preorder, INT_MIN, INT_MAX, idx);
        
        return idx == size(preorder);
    }
    
    void dfs(const vector<int>& preorder, int lo, int hi, int& idx) {
        if (idx >= size(preorder) or preorder[idx] < lo or preorder[idx] > hi) {
            return;
        }
        
        int cur = preorder[idx++];
        
        dfs(preorder, lo, cur, idx);
        dfs(preorder, cur, hi, idx);
    }
};