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
    void flatten(TreeNode* root) {
        if (not root) {
            return;
        }
        
        TreeNode *cur = root;
        
        while (cur) {
            if (cur->left) {
                TreeNode *rightmost = cur->left;
                
                while (rightmost->right) {
                    rightmost = rightmost->right;
                }
                
                rightmost->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            } else {
                cout << cur->val << endl;
                cur = cur->right;
            }
        }
    }
};