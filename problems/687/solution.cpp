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
    int helper(TreeNode* root, int parent, int& ans) {
        if (not root) {
            return 0;
        }

        int left = helper(root->left, root->val, ans),
            right = helper(root->right, root->val, ans);
        ans = max(ans, left + right);

        return root->val == parent ? max(left, right) + 1 : 0;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;

        helper(root, -1, ans);

        return ans;
    }
};