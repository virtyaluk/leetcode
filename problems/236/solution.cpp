/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = nullptr;
        unordered_set<TreeNode*> us = {p, q};
        
        dfs(root, us, ans);
        
        return ans;
    }
    
    int dfs(TreeNode *root, unordered_set<TreeNode*>& us, TreeNode*& ans) {
        if (not root) {
            return 0;
        }
        
        int match = dfs(root->left, us, ans)
            + dfs(root->right, us, ans)
            + us.count(root);
        
        if (match >= size(us) and not ans) {
            ans = root;
        }
        
        return match;
    }
};