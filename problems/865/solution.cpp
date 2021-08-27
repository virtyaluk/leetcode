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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto [node, _] = find(root);
        
        return node;
    }
    
    pair<TreeNode*, int> find(TreeNode* node) {
        if (!node) {
            return {nullptr, 0};
        }
        
        auto [lnode, lh] = find(node->left);
        auto [rnode, rh] = find(node->right);
        
        if (lh == rh) {
            return {node, lh + 1};
        } else if (lh > rh) {
            return {lnode, lh + 1};
        }
        
        return {rnode, rh + 1};
    }
};