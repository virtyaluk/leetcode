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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        helper(root, ans);
        
        return ans;
    }
    
    int helper(TreeNode* root, int& ans) {
        if (not root) {
            return 0;
        }
        
        int lval = helper(root->left, ans),
            rval = helper(root->right, ans);
        
        ans = max(ans, lval + rval);
        
        return 1 + max(lval, rval);
    }
};