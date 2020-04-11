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
    bool isSymmetric(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push(make_pair(root, root));
        
        while (!q.empty()) {
            auto [left, right] = q.front();
            q.pop();
            
            if (!left && !right) {
                continue;
            }
            
            if (!left || !right) {
                return false;
            }
            
            if (left->val != right->val) {
                return false;
            }
            
            q.push(make_pair(left->left, right->right));
            q.push(make_pair(left->right, right->left));
        }
        
        return true;
    }
};