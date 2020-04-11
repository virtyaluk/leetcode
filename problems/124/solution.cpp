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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        
        helper(root, ans);
        
        return ans;
    }
    
    int helper(TreeNode* root, int& ans) {
        if (not root) {
            return 0;
        }
        
        int lval = max(0, helper(root->left, ans)),
            rval = max(0, helper(root->right, ans));
        
        ans = max(ans, lval + root->val + rval);
        
        return root->val + max(lval, rval);
    }
};