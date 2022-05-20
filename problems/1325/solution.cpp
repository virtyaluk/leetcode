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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (remove(root, target)) {
            return nullptr;
        }
        
        return root;
    }
    
    bool remove(TreeNode* root, int target) {
        if (not root) {
            return false;
        }
        
        if (remove(root->left, target)) {
            root->left = nullptr;
        }
        
        if (remove(root->right, target)) {
            root->right = nullptr;
        }
        
        return not root->left and not root->right and root->val == target;
    }
};