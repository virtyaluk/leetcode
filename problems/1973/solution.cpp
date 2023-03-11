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
    int equalToDescendants(TreeNode* root) {
        int ans = 0;
        
        dfs(root, ans);
        
        return ans;
    }
    
    long long int dfs(TreeNode *root, int& ans) {
        if (not root) {
            return 0;
        }
        
        long long int sum = dfs(root->left, ans) + dfs(root->right, ans);
        ans += sum == root->val;
        
        return sum + root->val;
    }
};