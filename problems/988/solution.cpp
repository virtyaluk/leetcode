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
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        queue<pair<TreeNode*, string>> q;
        q.push({root, ""});
        
        while (!q.empty()) {
            auto [node, str] = q.front();
            q.pop();
            
            str += 'a' + node->val;

            if (!node->left && !node->right) {
                reverse(str.begin(), str.end());
                
                if (ans.empty() || str < ans) {
                    ans = str;
                }
            }
            
            if (node->left) {
                q.push({node->left, str});
            }
            
            if (node->right) {
                q.push({node->right, str});
            }
        }
        
        return ans;
    }
};