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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (not root) {
            return {};
        }
        
        vector<string> ans;
        queue<pair<TreeNode*, string>> q;
        
        q.push({root, ""});
        
        while (not q.empty()) {
            auto [node, path] = q.front();
            q.pop();
            
            path += to_string(node->val);
            
            if (not node->left and not node->right) {
                ans.push_back(path);
                continue;
            }
            
            path += "->";
            
            if (node->left) {
                q.push({node->left, path});
            }
            
            if (node->right) {
                q.push({node->right, path});
            }
        }
        
        return ans;
    }
};