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
    TreeNode* convertBST(TreeNode* root) {
        int acc = 0;
        TreeNode *cur = root, *prev = nullptr;
        
        while (cur) {
            if (cur->right) {
                prev = cur->right;
                
                while (prev->left && prev->left != cur) {
                    prev = prev->left;
                }
                
                if (!prev->left) {
                    prev->left = cur;
                    cur = cur->right;
                } else {
                    prev->left = nullptr;
                    
                    helper(cur, acc);
                    
                    cur = cur->left;
                }
            } else {
                helper(cur, acc);
    
                cur = cur->left;
            }
        }
        
        return root;
    }
    
    void helper(TreeNode *node, int& acc) {
        int tmp = node->val;
        node->val += acc;
        acc += tmp;
    }
    
    int acc = 0;
    TreeNode* convertBST1(TreeNode* root) {
        if (!root) {
            return root;
        }
        
        helper1(root);
        
        return root;
    }
    
    void helper1(TreeNode *node) {
        if (!node) {
            return;
        }
        
        helper1(node->right);
        
        int tmp = node->val;
        node->val += acc;
        acc += tmp;
        
        cout << node->val << endl;
        
        helper1(node->left);
    }
};