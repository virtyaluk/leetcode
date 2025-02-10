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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        
        q.push({nullptr, root});
        
        while (not empty(q)) {
            unordered_map<TreeNode*, long long> um;
            int total = 0;
            
            for (int qLen = size(q); qLen > 0; qLen--) {
                auto [parent, node] = q.front();
                um[parent] += node->val;
                
                q.pop();
                q.push({parent, node});
            }
            
            for (auto [_, sum]: um) {
                total += sum;
            }
            
            for (int qLen = size(q); qLen > 0; qLen--) {
                auto [parent, node] = q.front();
                node->val = total - um[parent];
                
                q.pop();
                
                if (node->left) {
                    q.push({node, node->left});
                }
                
                if (node->right) {
                    q.push({node, node->right});
                }
            }
        }
        
        return root;
    }
};