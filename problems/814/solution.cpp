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
    TreeNode* pruneTree(TreeNode* root) {
        if (not root) {
            return nullptr;
        }
        
        TreeNode *left = pruneTree(root->left),
            *right = pruneTree(root->right);
        
        root->left = left;
        root->right = right;
        
        return root->val == 1 or left or right ? root : nullptr;
    }
};