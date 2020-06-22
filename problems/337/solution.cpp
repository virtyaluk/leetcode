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
    int rob(TreeNode* root) {
        pair<int, int> rob = helper(root);
        
        return max(rob.first, rob.second);
    }
    
    pair<int, int> helper(TreeNode* node) {
        if (!node) {
            return make_pair(0, 0);
        }
        
        pair<int, int> left = helper(node->left), right = helper(node->right);
        
        return make_pair(
            node->val + left.second + right.second,
            max(left.first, left.second) + max(right.first, right.second)
        );
    }
};