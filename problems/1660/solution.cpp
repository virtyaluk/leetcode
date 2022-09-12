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
    TreeNode* correctBinaryTree(TreeNode* root) {
        dfs(root, true);
        dfs(root, false);
        
        return root;
    }
    
    TreeNode* dfs(TreeNode* root, bool check) {
        if (not root) {
            return root;
        }
        
        if (check) {
            if (root->val >= 0) {
                root->val += 1e9 + 1;
            } else {
                root->val -= (1e9 + 1);
            }
            
            if (root->right and (root->right->val < -1e9 or root->right->val > 1e9)) {
                return nullptr;
            }
        } else {
            if (root->val >= 0) {
                root->val -= (1e9 + 1);
            } else {
                root->val += 1e9 + 1;
            }
        }
        
        root->right = dfs(root->right, check);
        root->left = dfs(root->left, check);
        
        return root;
    }
};