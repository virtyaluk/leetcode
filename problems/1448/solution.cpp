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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        
        helper(root, INT_MIN, ans);
        
        return ans;
    }
    
    void helper(TreeNode *root, int curMax, int& ans) {
        if (not root) {
            return;
        }
        
        if (root->val >= curMax) {
            ans++;
        }
        
        curMax = max(curMax, root->val);
        
        helper(root->left, curMax, ans);
        helper(root->right, curMax, ans);
    }
};