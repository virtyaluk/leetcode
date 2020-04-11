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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        
        dfs(root, targetSum, ans);
        
        return ans;
    }
    
     void dfs(TreeNode* root, int sum, bool& ans) {
         if (not root or ans) {
             return;
         }
         
         sum -= root->val;
         
         if (not root->left and not root->right and not sum) {
             ans = true;
             return;
         }
         
         dfs(root->left, sum, ans);
         dfs(root->right, sum, ans);
     }
};