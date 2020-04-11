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
    int sumNumbers(TreeNode* root) {
        if (not root) {
            return 0;
        }
        
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        
        while (not empty(q)) {
            auto [node, curVal] = q.front();
            q.pop();
            
            curVal = curVal * 10 + node->val;
            
            if (not node->left and not node->right) {
                ans += curVal;
            }
            
            if (node->left) {
                q.push({node->left, curVal});
            }
            
            if (node->right) {
                q.push({node->right, curVal});
            }
        }
        
        return ans;
    }
};