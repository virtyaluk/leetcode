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
    TreeNode *one, *two, *prev;
    
    void recoverTree(TreeNode* root) {
        traverse(root);
        
        one->val ^= two->val;
        two->val ^= one->val;
        one->val ^= two->val;
    }
    
    void traverse(TreeNode* node) {
        if (!node) {
            return;
        }
        
        traverse(node->left);
        
        if (prev && prev->val > node->val) {
            if (!one) {
                one = prev;
            }
            
            two = node;
        }
        
        prev = node;
        traverse(node->right);
    }
};