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
    TreeNode* next;

    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        
        TreeNode* dummy = new TreeNode();
        next = dummy;
        
        traverse(root);
        
        return dummy->right;
    }
    
    void traverse(TreeNode* node) {
        if (!node) {
            return;
        }
        
        traverse(node->left);
        
        node->left = nullptr;
        next->right = node;
        next = node;
        
        traverse(node->right);
    }
};