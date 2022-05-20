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
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, count] = q.front();
            q.pop();
            
            if (!node) {
                continue;
            }
            
            count ^= 1 << (node->val - 1);
            
            if (node->left == node->right && (count & (count - 1)) == 0) {
                ans++;
            }
            
            q.push({node->left, count});
            q.push({node->right, count});
        }
        
        return ans;
    }
};