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
    bool evaluateTree(TreeNode* root) {
        if (not root) {
            return false;
        }
        
        if (root->val == 0 or root->val == 1) {
            return root->val == 1;
        }
        
        if (root->val == 2) {
            return evaluateTree(root->left) or evaluateTree(root->right);
        }
        
        return evaluateTree(root->left) and evaluateTree(root->right);
    }
};