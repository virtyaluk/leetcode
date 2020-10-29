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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int qsize = q.size() - 1;
            
            for (int i = qsize; i >= 0; i--) {
                root = q.front();
                
                q.pop();
                
                if (root->right) {
                    q.push(root->right);
                }
                
                if (root->left) {
                    q.push(root->left);
                }
            }
        }
        
        return root->val;
    }
};