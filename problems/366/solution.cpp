/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        
        dfs(root, ans);
        
        return ans;
    }
    
    int dfs(TreeNode* root, vector<vector<int>>& ans) {
        if (not root) {
            return 0;
        }
        
        int left = dfs(root->left, ans),
            right = dfs(root->right, ans),
            lvl = max(left, right);

        if (lvl >= size(ans)) {
            ans.push_back({});
        }
        
        ans[lvl].push_back(root->val);
        
        return lvl + 1;
    }
};