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
    vector<int> largestValues(TreeNode* root) {
        if (not root) {
            return {};
        }
        
        vector<int> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (not q.empty()) {
            int maxEl = INT_MIN;
            
            for (int qlen = q.size() - 1; qlen >= 0; qlen--) {
                TreeNode *node = q.front();
                q.pop();
                
                maxEl = max(maxEl, node->val);
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            ans.push_back(maxEl);
        }
        
        return ans;
    }
};