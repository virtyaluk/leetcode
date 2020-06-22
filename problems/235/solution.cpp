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
        
        dfs(root, p, q, ans);
        
        return ans;
    }
    
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&ans) {
        if (not root) {
            return false;
        }
        
        bool left = dfs(root->left, p, q, ans),
            right = dfs(root->right, p, q, ans),
            cur = root == p or root == q;
        
        if (left + cur + right >= 2) {
            ans = root;
        }
        
        return left + cur + right > 0;
    }
};