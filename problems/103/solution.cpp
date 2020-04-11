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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (!q.empty()) {
            ans.push_back({});
            
            for (int qLen = q.size(); qLen > 0; qLen--) {
                TreeNode *node = q.front();
                q.pop();
                
                ans.back().push_back(node->val);
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        
        for (int i = 0; i < ans.size(); i++) {
            if (i % 2 == 1) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        
        return ans;
    }
};