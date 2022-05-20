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
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        
        dfs(root, true, 0, ans);
        dfs(root, false, 0, ans);
        
        return ans;
    }
    
    void dfs(TreeNode* root, bool goLeft, int path, int &ans) {
        if (not root) {
            return;
        }
        
        ans = max(ans, path);
        
        if (goLeft) {
            dfs(root->left, false, path + 1, ans);
            dfs(root->left, true, 0, ans);
        } else {
            dfs(root->right, true, path + 1, ans);
            dfs(root->right, false, 0, ans);
        }
    }
};