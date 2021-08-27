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
    int dfs(TreeNode* node, int& ans) {
        if (not node) {
            return 0;
        }
        
        int l = dfs(node->left, ans),
            r = dfs(node->right, ans);
        
        ans += abs(l) + abs(r);
        
        return node->val + l + r - 1;
    }

public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        
        dfs(root, ans);
        
        return ans;
    }
};