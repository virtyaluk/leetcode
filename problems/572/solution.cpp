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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s, t);
    }
    
    bool traverse(TreeNode* s, TreeNode* t) {
        return s && (eq(s, t) || traverse(s->left, t) || traverse(s->right, t));
    }
    
    bool eq(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        }
        
        if (!s || !t) {
            return false;
        }
        
        return s->val == t->val && eq(s->left, t->left) && eq(s->right, t->right);
    }
};