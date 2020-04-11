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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            ans++;
            
            for (int i = q.size(); i > 0; i--) {
                TreeNode* cur = q.front();
                q.pop();
                
                if (!cur->left && !cur->right) {
                    return ans;
                }
                
                if (cur->left) {
                    q.push(cur->left);
                }
                
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        
        return ans;
    }
};