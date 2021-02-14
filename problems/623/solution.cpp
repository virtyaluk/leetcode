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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (not root) {
            return nullptr;
        }
        
        if (d == 1) {
            return new TreeNode(v, root, nullptr);
        }
        
        queue<TreeNode*> q;
        int curDepth = 1;
        d--;
        
        q.push(root);
        
        while (not q.empty()) {
            for (int i = q.size() - 1; i >= 0; i--) {
                TreeNode *node = q.front();
                q.pop();
                
                if (curDepth == d) {
                    node->left = new TreeNode(v, node->left, nullptr);
                    node->right = new TreeNode(v, nullptr, node->right);
                    continue;
                }
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            curDepth++;
        }
        
        return root;
    }
};