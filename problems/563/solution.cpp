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
    int ans = 0;
    int findTilt(TreeNode* root) {
        traverse(root);
        
        return ans;
    }
    
    int traverse(TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        int left = traverse(node->left), right = traverse(node->right);
        ans += abs(left - right);
        
        return left + right + node->val;
    }
};