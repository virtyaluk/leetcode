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
private:
    int lastSum = 0;

public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        
        return root;
    }
    
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        
        dfs(node->right);
        
        lastSum += node->val;
        node->val = lastSum;
        
        dfs(node->left);
    }
};